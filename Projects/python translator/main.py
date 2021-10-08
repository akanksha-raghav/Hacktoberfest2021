import os
import io
import pygame
import textwrap
import threading
from tkinter import *
from tkinter.ttk import *
from tkinter import ttk
from gtts import gTTS
from googletrans import Translator
from PyDictionary import PyDictionary
from langcodes import LANGCODES


class Translator_App(object):
    def __init__(self, master):
        frame = Frame(master)
        frame.grid()
        tabControl = ttk.Notebook(root)
        tabControl.configure(width=340, height=400)

        self.translate_tab = ttk.Frame(tabControl)
        tabControl.add(self.translate_tab, text='Translate')
        tabControl.grid()
        self.translate_tab.grid_propagate(0)

        self.about_tab = ttk.Frame(tabControl)
        tabControl.add(self.about_tab, text='About')
        tabControl.grid()

        self.speak_it = BooleanVar()
        self.languages = LANGCODES
        self.translate_page()
        self.about_page()

    def translate_page(self):
        self.top_label = Label(self.translate_tab, text="Enter Word:")
        self.top_label.grid(column=0, row=0)

        self.word_entry = Entry(self.translate_tab, width=48)
        self.word_entry.grid(column=0, row=1, columnspan=3, padx=5, pady=5)

        self.language_label = Label(self.translate_tab, text='Language: ')
        self.language_label.grid(column=0, row=2, pady=5)

        self.language_menu = ttk.Combobox(
            self.translate_tab, values=[*self.languages.keys()])
        self.language_menu.grid(column=1, row=2)
        self.language_menu.current(0)

        self.translate_button = Button(
            self.translate_tab, text='Translate!', command=self.translation_function)
        self.translate_button.grid(column=0, row=3, pady=15)

        self.speak_check = Checkbutton(
            self.translate_tab, text='Say It!', variable=self.speak_it)
        self.speak_check.grid(column=1, row=3)

        self.word_frame = Labelframe(
            self.translate_tab, text='Word:', width=300, height=50)
        self.word_frame.grid(column=0, row=4, columnspan=3)
        self.word_frame.grid_propagate(0)
        self.word_result = Label(self.word_frame, text='')
        self.word_result.grid()

        self.noun_frame = Labelframe(
            self.translate_tab, text='Noun:', width=300, height=100)
        self.noun_frame.grid(column=0, row=5, columnspan=3)
        self.noun_frame.grid_propagate(0)
        self.noun_result = Label(self.noun_frame, text='')
        self.noun_result.grid()

        self.verb_frame = Labelframe(
            self.translate_tab, text='Verb:', width=300, height=100)
        self.verb_frame.grid(column=0, row=6, columnspan=3)
        self.verb_frame.grid_propagate(0)
        self.verb_result = Label(self.verb_frame, text='')
        self.verb_result.grid()

    def translation_function(self):
        word = self.word_entry.get()
        language = self.languages.get(self.language_menu.get())

        noun, verb = self.definition(word)
        try:
            noun = str(*noun[0])
            verb = str(*verb[0])
        except:
            noun = str(noun[0])
            verb = str(verb[0])

        translated_word = self.translate_func(word, language).text
        translated_noun = self.translate_func(noun, language).text
        translated_verb = self.translate_func(verb, language).text
        speak_thread = threading.Thread(
            target=self.speak, args=(translated_word, language))

        self.word_result.configure(text=translated_word)
        self.noun_result.configure(text=textwrap.fill(translated_noun, 50))
        self.verb_result.configure(text=textwrap.fill(translated_verb, 50))
        if self.speak_it.get():
            speak_thread.start()

    def definition(self, word):
        nouns, verbs = [], []
        dictionary = PyDictionary()
        word = self.translate_func(word, 'en').text
        my_meaning = dictionary.meaning(word)
        try:
            if my_meaning['Noun']:
                nouns.append(my_meaning['Verb'][0])
            if my_meaning['Verbs']:
                verbs.append(my_meaning['Noun'][0])
        except:
            nouns.append("No Data")
            verbs.append("No Data")
        return nouns, verbs

    def translate_func(self, words, language):
        translator = Translator(service_urls=["translate.google.com"])
        translation = translator.translate(words, dest=language)
        return translation

    def speak(self, text, language):
        with io.BytesIO() as file:
            gTTS(text=text, lang=language).write_to_fp(file)
            file.seek(0)
            pygame.mixer.init()
            pygame.mixer.music.load(file)
            pygame.mixer.music.play()
            while pygame.mixer.music.get_busy():
                continue

    def about_page(self):
        label = Label(self.about_tab, text="""
        This is a small python gui project which is a translator
        Made by Gaurav Kulkarni
        Note:- Internet connection is required to run the app""")
        label.place(y=150, x=20)


if __name__ == '__main__':
    root = Tk()
    root.title("Translator")
    root.geometry("350x430")
    Translator_App(root)
    root.mainloop()
