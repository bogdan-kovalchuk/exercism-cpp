#include <string>

namespace log_line
{
    std::string message(std::string line)
    {
        const std::size_t separator = line.find(": ");
        return line.substr(separator + 2);
    }

    std::string log_level(std::string line)
    {
        const std::size_t left_bracket = line.find('[');
        const std::size_t right_bracket = line.find(']');
        return line.substr(left_bracket + 1, right_bracket - left_bracket - 1);
    }

    std::string reformat(std::string line)
    {
        const std::string extracted_message = message(line);
        const std::string extracted_level = log_level(line);
        return extracted_message + " (" + extracted_level + ")";
    }
} // namespace log_line
