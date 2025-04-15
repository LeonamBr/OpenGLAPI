#ifndef LOG_H
#define LOG_H

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>


class Log{

    public:

        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetLogger(){return s_Logger;}


    private:

        static std::shared_ptr<spdlog::logger> s_Logger;

    };

template<typename OStream, glm::length_t L, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::vec<L, T, Q>& vector)
{
	return os << glm::to_string(vector);
}

template<typename OStream, glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::mat<C, R, T, Q>& matrix)
{
	return os << glm::to_string(matrix);
}

template<typename OStream, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, glm::qua<T, Q> quaternion)
{
	return os << glm::to_string(quaternion);
}

#define LOG_TRACE(...)      Log::GetLogger()->trace(__VA_ARGS__)
#define LOG_DEBUG(...)      Log::GetLogger()->debug(__VA_ARGS__)
#define LOG_INFO(...)       Log::GetLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)       Log::GetLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)      Log::GetLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...)   Log::GetLogger()->critical(__VA_ARGS__)

#endif