#include "spdlog/spdlog.h"

#define FROG_LOG(...) ::spdlog::info(__VA_ARGS__);
#define FROG_WARN(...) ::spdlog::warn(__VA_ARGS__);
#define FROG_ERROR(...) ::spdlog::error(__VA_ARGS__);
#define FROG_CRITICAL(...) ::spdlog::critical(__VA_ARGS__);
#define print(...) ::spdlog::info(__VA_ARGS__);