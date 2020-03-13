#include "gtest/gtest.h"

#include "framebuffer.h"

namespace
{

using namespace cannelloni;

TEST(CanTest, CanReallyTest)
{
    EXPECT_EQ(0, 0);
}

TEST(FrameBufferTest, CheckSize0) {
  FrameBuffer buffer(0, 0);
  EXPECT_EQ(0, buffer.getFrameBufferSize());
}

TEST(FrameBufferTest, CheckSize1) {
  FrameBuffer buffer(0, 0);
  EXPECT_EQ(0, buffer.getFrameBufferSize());
}

} // namespace

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
