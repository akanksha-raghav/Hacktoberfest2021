import pyttsx3
import datetime
import speech_recognition as sr
import wikipedia
import smtplib
import webbrowser as wb
import os
import pyautogui
import psutil
import pyjokes

# ----------------IF YOU HAVE ANY PROBLEM FOR INSTALLING LIBRARIES JUST CHECKOUT README FILE--------------------

engine = pyttsx3.init()


# Speak function is used to add voice to the A.I
def speak(audio):
    engine.say(audio)
    engine.runAndWait()


# This function helps us to tell the current time
def time():
    real_time = datetime.datetime.now().strftime("%I:%M:%S")
    speak("the current time is")
    speak(real_time)


# This is used to tell the current date
def date():
    year = int(datetime.datetime.now().year)
    month = int(datetime.datetime.now().month)
    day = int(datetime.datetime.now().day)
    speak("And Today's date is")
    speak(day)
    speak(month)
    speak(year)


# This Function wishes us according to the time
def wish_me():
    hour = datetime.datetime.now().hour
    if 12 > hour >= 6:
        speak("Good Morning sir!")
    elif 18 > hour >= 12:
        speak("Good Afternoon sir!")
    elif 24 > hour >= 18:
        speak("Good evening sir!")
    else:
        speak("Good night sir!")
    speak("Welcome Back")
    speak("JARVIS at your service. Please tell me how can i help you?")


# This function helps us to take our command or sentence
def take_command():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening.....")
        r.pause_threshold = 1
        audio = r.listen(source)
        try:
            print("Recognizing.....")
            query = r.recognize_google(audio, language='en-in')
            print(query)

        except Exception as e:
            print(e)
            speak("Say That again Please!!")
            return "None"

        return query


# This function helps us to send a email
def send_email(to, content):
    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.ehlo()
    server.starttls()
    server.login('senders_email@gmail.com', 'password')
    server.sendmail('receivers_email.com', to, content)
    server.quit()


# This Function helps us to take Screenshots
def screenshot():
    img = pyautogui.screenshot()
    img.save("File_location\ss.png")


# Tell the CPU current usage and the Battery life
def cpu():
    usage = str(psutil.cpu_percent())
    speak("CPU is at "+usage+"percent")
    battery = str((psutil.sensors_battery()).percent)
    speak("Battery is at "+battery+" percent")


# Tell jokes related to languages
def jokes():
    joke = pyjokes.get_joke()
    print(joke)
    speak(joke)


if __name__ == "__main__":
    wish_me()
    while True:
        query = take_command().lower()
        # TELL THE CURRENT TIME
        if "time" in query:
            time()
        # TELL THE CURRENT DATE
        elif "date" in query:
            date()
        # SEARCH ON WIKIPEDIA
        elif "wikipedia" in query:
            speak("Just a sec")
            query = query.replace("wikipedia", "")
            result = wikipedia.summary(query, sentences=2)
            print(result)
            speak(result)
        # SEND EMAILS
        elif "send email" in query:
            try:
                speak("What Your Mail")
                content = take_command()
                to = 'sakshitatiya774@gmail.com'
                send_email(to, content)
                speak("Email has been sent")
            except Exception as e:
                print(e)
                speak("Unable to send the email")
        # SEARCH ON CHROME
        elif "search in chrome" in query:
            speak("What should i search ?")
            chrome_path = 'C:/Program Files/Google/Chrome/Application/chrome.exe %s'
            search = take_command().lower()
            wb.get(chrome_path).open_new_tab(search + '.com')
        # LOGOUT FROM THE WINDOWS
        elif 'logout' in query:
            os.system("shutdown -1")
        # SHUTDOWN THE WINDOWS
        elif 'shutdown' in query:
            os.system("shutdown /s /t 1")
        # RESTART THE WINDOWS
        elif 'restart' in query:
            os.system("shutdown /r /t 1")
        # PLAY SONGS FROM THE SYSTEM
        elif "play songs" in query:
            songs_dir = 'D:\\Music'
            songs = os.listdir(songs_dir)
            os.startfile(os.path.join(songs_dir, songs[1]))
        # REMEMBER WE SAID TO REMEMBER
        elif 'remember that' in query:
            speak("What should i remember")
            data = take_command()
            speak("Okay. I will remember that ")
            remember = open('data.txt', 'w')
            remember.write(data)
            remember.close()
        # TO REMEMBER THE PREVIOUS TEXT
        elif 'do you remember' in query:
            remember = open('data.txt', 'r')
            speak("you said me to remember that"+remember.read())
        # TAKE A SCREENSHOT
        elif 'screenshot' in query:
            screenshot()
            speak("Screenshot is taken!")
        # CPU USAGE AND BATTERY PERCENTAGE
        elif 'cpu' in query:
            cpu()
        # MAKE A JOKE
        elif 'joke' in query:
            jokes()
        # GO OFFLINE JARVIS
        elif "offline" in query:
            quit()
