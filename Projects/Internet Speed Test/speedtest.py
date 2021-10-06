# install the library 'speedtest-cli' first if you haven't
# pip install speedtest-cli

import speedtest
check  = speedtest.Speedtest()
print("Download Speed is ", check.download())
print("Upload Speed is ", check.upload())