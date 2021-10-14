from tkinter import*
import tkinter.scrolledtext as scrolledtext
from tkinter.filedialog import askopenfilename, asksaveasfilename
import os

root = Tk()
root.title('Python Notepad')
root.geometry('600x600+350+40')
Textarea = scrolledtext.ScrolledText(root, font='Lucida 13')
Textarea.pack(expand=True, fill=BOTH)
file = None

# ===create menu=============
MenuBar = Menu(root)
root.config(menu=MenuBar)
# ==========================
FileMenu = Menu(MenuBar, tearoff=0)
EditMenu = Menu(MenuBar, tearoff=0)
MenuBar.add_cascade(label='File', menu=FileMenu)
MenuBar.add_cascade(label='Edit', menu=EditMenu)


def newFile():
    global file
    root.title('Untitled - Notepad')
    Textarea.delete(1.0, END)


def openFile():
    global file
    file = askopenfilename(defaultextension='.txt', filetypes=[('Text Documents', '*.txt')])
    if file == " ":
        file = None
    else:
        root.title(os.path.basename(file)+'-Notepad')
        f = open(file, 'r')
        Textarea.insert(1.0, f.read())
        f.close()


def saveFile():
    global file
    if file == None:
        file = asksaveasfilename(defaultextension='.txt', filetypes=[('All', '*.*'),
                                                                         ('Text Document', "*.txt")])
        if file == "":
            file = None
        else:
            f = open(file, 'w')
            f.write(Textarea.get(1.0, END))
            f.close()
            root.title(os.path.basename(file)+'-Notepad')

    else:
        f = open(file, 'w')
        f.write(Textarea.get(1.0, END))
        f.close()


def exitFile():
    root.destroy()


def cut():
    Textarea.event_generate('<<Cut>>')


def copy():
    Textarea.event_generate('<<Copy>>')


def paste():
    Textarea.event_generate('<<Paste>>')


FileMenu.add_command(label='New', command=newFile)
FileMenu.add_command(label='Open', command=openFile)
FileMenu.add_command(label='Save', command=saveFile)

FileMenu.add_separator()

FileMenu.add_command(label='Exit', command=exitFile)
EditMenu.add_command(label='Cut', command=cut)
EditMenu.add_command(label='Copy', command=copy)
EditMenu.add_command(label='Paste', command=paste)

root.mainloop()

