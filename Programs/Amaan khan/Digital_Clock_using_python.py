import tkinter
import time
window = tkinter.Tk()
window.title("clock")

def dig():
   clock = tkinter.Label(window, font=('times',40,'bold'), bg='pink')
   clock.pack(fill=tkinter.BOTH, expand=1)
   def time_change():
      global t1
      t1 = time.strftime('%H:%M:%S') # getting the current time from system
      clock.config(text=t1)
      clock.after(1000, time_change) # calls itself every 1000 milliseconds=1 seconds

   time_change()
tkinter.Button(window,text="Click it",font=('times',40,'bold'),fg='green',command=dig).pack()
window.mainloop(  )
