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
  size_t size = 100;
  size_t max = 150;

  FrameBuffer buffer(size, max);

  struct canfd_frame *frame = buffer.requestFrame(false, false);

  frame->can_id = 0;
  frame->len = 0;
  buffer.insertFrame(frame);

  EXPECT_EQ(CANNELLONI_FRAME_BASE_SIZE, buffer.getFrameBufferSize());
}

TEST(FrameBufferTest, CheckSize2) {
  size_t size = 100;
  size_t max = 150;
  size_t numFrames = 50;

  FrameBuffer buffer(size, max);

  for(size_t i = 0; i < numFrames; i++){
      struct canfd_frame *frame = buffer.requestFrame(false, false);
      frame->can_id = 0;
      frame->len = 0;
      buffer.insertFrame(frame);
  }
  EXPECT_EQ(CANNELLONI_FRAME_BASE_SIZE*numFrames, buffer.getFrameBufferSize());
}

TEST(FrameBufferTest, CheckSize3) {
  size_t size = 100;
  size_t max = 150;
  size_t numFrames = 100;

  FrameBuffer buffer(size, max);

  for(size_t i = 0; i < numFrames; i++){
      struct canfd_frame *frame = buffer.requestFrame(false, false);
      frame->can_id = 0;
      frame->len = 0;
      buffer.insertFrame(frame);
  }
  EXPECT_EQ(CANNELLONI_FRAME_BASE_SIZE*numFrames, buffer.getFrameBufferSize());
}

TEST(FrameBufferTest, CheckSize4) {
  size_t size = 100;
  size_t max = 150;
  size_t numFrames = 120;

  FrameBuffer buffer(size, max);

  for(size_t i = 0; i < numFrames; i++){
      struct canfd_frame *frame = buffer.requestFrame(false, false);
      frame->can_id = 0;
      frame->len = 0;
      buffer.insertFrame(frame);
  }
  EXPECT_EQ(CANNELLONI_FRAME_BASE_SIZE*numFrames, buffer.getFrameBufferSize());
}

TEST(FrameBufferTest, CheckSize5) {
  size_t size = 100;
  size_t max = 150;
  size_t numFrames = 150;

  FrameBuffer buffer(size, max);

  for(size_t i = 0; i < numFrames; i++){
      struct canfd_frame *frame = buffer.requestFrame(false, false);
      frame->can_id = 0;
      frame->len = 0;
      buffer.insertFrame(frame);
  }
  EXPECT_EQ(CANNELLONI_FRAME_BASE_SIZE*numFrames, buffer.getFrameBufferSize());
}

TEST(FrameBufferTest, CheckSize6) {
  size_t size = 100;
  size_t max = 150;
  size_t numFrames = 170;

  FrameBuffer buffer(size, max);

  for(size_t i = 0; i < numFrames; i++){
      struct canfd_frame *frame = buffer.requestFrame(false, false);
      if ( NULL != frame ){
          frame->can_id = 0;
          frame->len = 0;
          buffer.insertFrame(frame);
      }
  }
  EXPECT_EQ(CANNELLONI_FRAME_BASE_SIZE*max, buffer.getFrameBufferSize());
}

TEST(FrameBufferTest, checkAddresses) {
  size_t size = 20;
  size_t max = 25;
  size_t numFrames = 20;

  FrameBuffer buffer(size, max);

  std::vector<struct canfd_frame *> frames;

  for(size_t i = 0; i < numFrames; i++){
      frames.push_back(buffer.requestFrame(false, false));
      buffer.insertFramePool(frames[i]);
  }

  for ( size_t i = 0; i < 10; i++){
      for(size_t i = 0; i < numFrames; i++){
          EXPECT_EQ(frames[i], buffer.requestFrame(false, false));
          buffer.insertFramePool(frames[i]);
      }
  }

}


} // namespace

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
