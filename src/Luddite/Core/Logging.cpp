#include "Luddite/Core/Logging.hpp"
#include "spdlog/sinks/stdout_color_sinks.h"

#include "Luddite/Platform/DiligentPlatform.hpp"
#include "Primitives/interface/DebugOutput.h"

namespace Luddite
{
std::shared_ptr<spdlog::logger> Logger::core_console;
std::shared_ptr<spdlog::logger> Logger::app_console;
std::shared_ptr<spdlog::logger> Logger::diligent_console;

void Logger::Init()
{
        spdlog::set_pattern("%T %^[%8n] %v%$");

        core_console = spdlog::stdout_color_mt("Core");
        core_console->set_level(spdlog::level::trace);

        app_console = spdlog::stdout_color_mt("App");
        app_console->set_level(spdlog::level::trace);

        diligent_console = spdlog::stdout_color_mt("Diligent");
        diligent_console->set_level(spdlog::level::trace);
}
}
