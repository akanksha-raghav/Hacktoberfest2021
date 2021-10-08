from pynput.keyboard import Key, Listener
import winsound
import string


keyReleaseDict={}
for keys in Key:
    keyReleaseDict[str(keys)] = True
for alphabets in string.printable:
    if alphabets == "'":
        quote = "'"
        keyReleaseDict[f'"{quote}"'] = True
        continue
    elif alphabets == "\\":
        keyReleaseDict["'\\\\'"] = True
        continue
    else:
        keyReleaseDict[f"'{alphabets}'"] = True
#print(keyReleaseDict)

def playDownSound(key):
    #Check if key has been release
    try:
        if keyReleaseDict[str(key)] == True: # and active:
            if key == Key.space:
                winsound.PlaySound('Sounds/space.wav', winsound.SND_ASYNC)
            elif key == Key.backspace:
                winsound.PlaySound('Sounds/backspace.wav', winsound.SND_ASYNC)
            elif key == Key.enter:
                winsound.PlaySound('Sounds/enter.wav', winsound.SND_ASYNC)
            else:
                winsound.PlaySound('Sounds/normal.wav', winsound.SND_ASYNC)
    except:
        winsound.PlaySound('Sounds/normal.wav', winsound.SND_ASYNC)
    #print(key)
    keyReleaseDict[str(key)] = False
def playReleaseSound(key):
    #if active:

    keyReleaseDict[str(key)] = True
    if key == Key.space:
        winsound.PlaySound('Sounds/relspace.wav', winsound.SND_ASYNC)
    elif key == Key.backspace:
        winsound.PlaySound('Sounds/relbackspace.wav', winsound.SND_ASYNC)
    elif key == Key.enter:
        winsound.PlaySound('Sounds/relenter.wav', winsound.SND_ASYNC)
    else:
        winsound.PlaySound('Sounds/release.wav', winsound.SND_ASYNC)

with Listener(on_press=playDownSound, on_release=playReleaseSound) as listener:
    #root.mainloop()
    listener.join()
