
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

TEST(ExecutorTest, should_return_default_pose_when_without_init_and_command)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor());

    // when

    // then
    const Pose target({0, 0, 'N'});
    ASSERT_EQ(target, executor->Query());
}

// 用例3：向东移动1步
TEST(ExecutorTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E)
{
    // given：初始化小车，位置为(0, 0)，朝向东
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // when：执行移动指令
    executor->Execute("M");

    // then：预期x坐标加1，y坐标不变，朝向不变
    const Pose target({1, 0, 'E'});
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorTest, should_return_x_minus_1_given_command_is_M_and_facing_is_W)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));

    // when
    executor->Execute("M");

    // then
    const Pose target({-1, 0, 'W'});
    ASSERT_EQ(target, executor->Query());
}

}  // namespace adas
