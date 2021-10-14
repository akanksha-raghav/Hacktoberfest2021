import os
import shutil

folders = {"Images": [".jpeg", ".jpg", ".tiff", ".gif", ".bmp", ".png", ".bpg", "svg",
               ".heif", ".psd", ".ico"], "Music": [".aac", ".aa", ".aac", ".dvf", ".m4a", ".m4b", ".m4p", ".mp3",
              ".msv", "ogg", "oga", ".raw", ".vox", ".wav", ".wma"], "Videos": [".avi", ".flv", ".wmv", ".mov", ".mp4", ".webm", ".vob", ".mng",
               ".qt", ".mpg", ".mpeg", ".3gp"], "Archives": [".a", ".ar", ".cpio", ".iso", ".tar", ".gz", ".rz", ".7z",
                 ".dmg", ".rar", ".xar", ".zip"], "PDF Files": ['.pdf'], "Python Files": ['.py', '.pyw', '.ipynb', '.pyc'], "Applications": ['.exe', '.app', '.apk'], "Documents": ['.doc', '.docx', '.docm', '.dot'], "Spreadsheets": ['.xls', '.xlsx', '.xlsm'], "Text Files": [".txt", ".in", ".out"], "Java Files": ['.class', '.java'], "C++ Files": ['.c', '.cpp'], "JSON Files": [".json"], "Presentations": [".ppt", ".pptm", ".pptx"]}

extensions = {}
for folder,ext_list in folders.items():
    for ext in ext_list:
        extensions[ext] = folder

cwd = os.getcwd()

for file in os.listdir(cwd):
    if os.path.isfile(file):
        ext = os.path.splitext(file)[1]
        if ext in extensions:
            if not os.path.exists(f".\\{extensions[ext]}"):
                os.mkdir(f".\\{extensions[ext]}")
                shutil.move(file, f".\\{extensions[ext]}")
            else:
                shutil.move(file, f".\\{extensions[ext]}")
        else:
            if not os.path.exists(".\\Others"):
                os.mkdir(".\\Others")
                shutil.move(file, ".\\Others")
            else:
                shutil.move(file, ".\\Others")