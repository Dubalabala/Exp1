
#include "ExecutorImpl.hpp"

#include <new>

namespace adas
{
Executor* Executor::NewExecutor(const Pose& pose) noexcept
{
    return new (std::nothrow) ExecutorImpl(pose);
}

ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept : pose(pose)
{
}

void ExecutorImpl::Execute(const std::string& command) noexcept
{
    // 测试用例1暂时不需要实现指令功能
}

Pose ExecutorImpl::Query(void) const noexcept
{
    return pose;
}
}  // namespace adas
