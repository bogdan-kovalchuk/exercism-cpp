[CmdletBinding()]
param(
    [Parameter(Mandatory = $true)]
    [string]$ExercisePath,

    [switch]$RunAllTests,

    [switch]$Build
)

$vsDevShell = 'C:\Progra~2\MICROS~2\2022\BUILDT~1\Common7\Tools\Launch-VsDevShell.ps1'
$buildDir = 'build'

function Normalize-PathForComparison {
    param(
        [Parameter(Mandatory = $true)]
        [string]$Path
    )

    return $Path.Replace('\', '/').TrimEnd('/').ToLowerInvariant()
}

if (-not (Test-Path -LiteralPath $vsDevShell)) {
    throw "Visual Studio developer shell script not found at '$vsDevShell'."
}

& $vsDevShell -Arch amd64 -HostArch amd64
Set-Location -LiteralPath $ExercisePath

function Reset-CMakeBuildIfNeeded {
    $cachePath = Join-Path -Path $PWD -ChildPath "$buildDir\CMakeCache.txt"
    if (-not (Test-Path -LiteralPath $cachePath)) {
        return
    }

    $cacheSourceLine = Select-String -LiteralPath $cachePath -Pattern '^CMAKE_HOME_DIRECTORY:INTERNAL=' | Select-Object -First 1
    if (-not $cacheSourceLine) {
        return
    }

    $cachedSource = $cacheSourceLine.Line.Substring('CMAKE_HOME_DIRECTORY:INTERNAL='.Length)
    $currentSource = (Get-Location).Path

    if ((Normalize-PathForComparison $cachedSource) -ne (Normalize-PathForComparison $currentSource)) {
        Write-Host "Resetting stale CMake cache in '$buildDir' for '$currentSource'."
        Remove-Item -LiteralPath $cachePath -Force -ErrorAction SilentlyContinue
        Remove-Item -LiteralPath (Join-Path -Path $PWD -ChildPath "$buildDir\CMakeFiles") -Recurse -Force -ErrorAction SilentlyContinue
    }
}

if ($Build) {
    Reset-CMakeBuildIfNeeded
    if (-not (Test-Path -LiteralPath (Join-Path -Path $PWD -ChildPath "$buildDir\CMakeCache.txt"))) {
        & cmake -S . -B $buildDir -DEXERCISM_RUN_ALL_TESTS=1
        if ($LASTEXITCODE -ne 0) {
            exit $LASTEXITCODE
        }
    }
    & cmake --build $buildDir
    exit $LASTEXITCODE
}

$cmakeArgs = @('-S', '.', '-B', $buildDir)
if ($RunAllTests) {
    $cmakeArgs += '-DEXERCISM_RUN_ALL_TESTS=1'
}

Reset-CMakeBuildIfNeeded
& cmake @cmakeArgs
exit $LASTEXITCODE
