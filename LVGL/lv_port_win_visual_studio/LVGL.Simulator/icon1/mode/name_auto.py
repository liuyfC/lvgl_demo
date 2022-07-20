import os

#print(os.getcwd());

file_list = os.listdir(os.getcwd())

for file_name in file_list[1::]:
    #print(file_name.replace(".c", ""))
    print("LV_IMG_DECLARE(" + file_name.strip(".c") + ")" )