
#include <gtest/gtest.h>

#include <memory>
#include <tuple>

#include "Executor.hpp"

namespace adas
{
bool operator==(const Pose& lhs, const Pose& rhs)
{
    return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
}

TEST(ExecutorTest, should_return_init_pose_when_without_command)
{
    // given：创建初始位置为(0, 0)，朝向为E的车辆
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // when：不执行任何指令

    // then：检查车辆的状态是否保持不变
    const Pose target({0, 0, 'E'});
    ASSERT_EQ(target, executor->Query());
}
}  // namespace adas
