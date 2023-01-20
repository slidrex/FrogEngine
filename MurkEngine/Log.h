#include "spdlog/spdlog.h"

#define MURK_LOG(...) ::spdlog::info(__VA_ARGS__);
#define MURK_WARN(...) ::spdlog::warn(__VA_ARGS__);
#define MURK_ERROR(...) ::spdlog::error(__VA_ARGS__);
#define MURK_CRITICAL(...) ::spdlog::critical(__VA_ARGS__);
#define print(...) ::spdlog::info(__VA_ARGS__);