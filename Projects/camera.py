from kivy.core.image import Texture
import cv2
from typing import Text
from kivy.app import App
from kivy.uix.button import Button
from kivy.uix.image import Image
from kivy.uix.gridlayout import GridLayout
from kivy.clock import Clock
from kivy.graphics.texture import Texture
from datetime import datetime


class ControlPanel(GridLayout):  # here we can click , start,stop

    # for image
    def save_image(self, event):
        frame = self.main_layout.frame  # taking image from MainLayout

        # for generating dynamic datetime image name
        now = datetime.now()
        # coverting datetime into string
        date_time = now.strftime("%m-%d-%Y-%H-%M-%S")
        file_name = str(date_time)+".png"
        cv2.imwrite(file_name, frame)  # saving image

        # for video
    def start_video(self, event):
        self.start.disabled = True  # when video is recording disable start button
        self.stop.disabled = False  # when video is not recording disable stop button

        # to get size of frame
        # for frame width we find it on 3 rd index
        frame_w = int(self.main_layout.capture.get(3))
        # for frame height we find it on 4 th index
        frame_h = int(self.main_layout.capture.get(4))
        size = (frame_w, frame_h)

        # for generating dynamic datetime video name
        now = datetime.now()
        # coverting datetime into string
        date_time = now.strftime("%m-%d-%Y-%H-%M-%S")
        # will  write video frame
        self.videowriter = cv2.VideoWriter(
            "myvideo.avi", cv2.VideoWriter_fourcc(*'MJPG'), 10, size)
        self.videoClock = Clock.schedule_interval(self.write_frame, 1/10)

    def stop_video(self, event):
        self.start.disabled = False
        self.stop.disabled = True

        self.videowriter.release()  # to release video
        self.videoClock.release()  # to release clock

    def write_frame(self, event):
        self.videowriter.write(self.main_layout.frame)

    def __init__(self, main_layout, **kwargs):
        super(ControlPanel, self).__init__(**kwargs)
        self.videowriter = None
        self.rows = 1
        self.main_layout = main_layout
        self.click = Button(text="Click")
        self.start = Button(text="Video On")
        self.stop = Button(text="Video Off")
        self.video = False

        self.add_widget(self.click)
        self.add_widget(self.start)
        self.add_widget(self.stop)

        # whenever click is pressed save_image will be called
        self.click.bind(on_press=self.save_image)

        # whenever start is pressed video recording will on and off respectively
        self.start.bind(on_press=self.start_video)
        self.stop.bind(on_press=self.stop_video)


class MainLayout(GridLayout):  # making of main layout
    def update(self, event):
        retval, frame = self.capture.read()  # read-->gets image

        # if we get any image
        if retval:
            self.frame = frame
            # numpy 0 starts from top left so we have to reverse the list inorder to flip our frame
            flipped = frame[::-1]
            # converting frame into string-->because our image is in numpy array and however to apply texture we are converting it into string
            buf = flipped.tostring()
            # no. of columns as a first value and number of rows as a second  , cv2 supports bgr colorformat and not rgb
            texture = Texture.create(
                size=(frame.shape[1], frame.shape[0]), colorfmt="bgr")
            # bufferformat is unsigned byte i.e.0 to 255
            texture.blit_buffer(buf, colorfmt="bgr", bufferfmt='ubyte')

            self.image.texture = texture  # texture will be new texture

    def __init__(self, **kwargs):
        super(MainLayout, self).__init__(**kwargs)
        self.frame = frame = None

        # cv2 provides us this function and by default on 0 index its video capture
        self.capture = cv2.VideoCapture(0)
        self.rows = 2
        self.image = Image()  # we will take an image here
        self.control = ControlPanel(self)
        self.add_widget(self.image)  # image widget
        self.add_widget(self.control)  # control

        # after particular time interval we want to schedule update function
        # 1/30 frames per second it will change
        Clock.schedule_interval(self.update, 1/30)


class TestApp(App):

    def build(self):

        return MainLayout()


TestApp().run()