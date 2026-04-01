param(
    [Parameter(Mandatory = $true)]
    [ValidateSet("configure", "configure-all-tests", "build")]
    [string]$Action,

    [Parameter(Mandatory = $true)]
    [string]$ExercisePath
)

$ErrorActionPreference = "Stop"

$workspaceRoot = Split-Path -Parent $PSScriptRoot
$exerciseDir = Join-Path $workspaceRoot $ExercisePath

if (-not (Test-Path -LiteralPath $exerciseDir)) {
    throw "Exercise directory not found: $exerciseDir"
}

function Find-CMake {
    $cmd = Get-Command cmake -ErrorAction SilentlyContinue
    if ($cmd) {
        return $cmd.Source
    }

    $candidates = @(
        "C:\Program Files\CMake\bin\cmake.exe",
        "C:\Program Files (x86)\CMake\bin\cmake.exe"
    )

    foreach ($candidate in $candidates) {
        if (Test-Path -LiteralPath $candidate) {
            return $candidate
        }
    }

    throw "CMake was not found. Install CMake and make sure 'cmake' is available in PATH."
}

function Test-VisualStudioBuildToolsInstalled {
    $vswhere = "C:\Program Files (x86)\Microsoft Visual Studio\Installer\vswhere.exe"
    if (-not (Test-Path -LiteralPath $vswhere)) {
        return $false
    }

    $installationPath = & $vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
    return -not [string]::IsNullOrWhiteSpace($installationPath)
}

$cmake = Find-CMake

if (-not (Test-VisualStudioBuildToolsInstalled)) {
    throw "Visual Studio Build Tools with C++ workload were not found."
}

Set-Location -LiteralPath $exerciseDir

switch ($Action) {
    "configure" {
        & $cmake -S . -B build
    }
    "configure-all-tests" {
        & $cmake -S . -B build -DEXERCISM_RUN_ALL_TESTS=1
    }
    "build" {
        & $cmake --build build
    }
}
