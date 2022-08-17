from genericpath import isdir
from sys import exit
import re
import time
import os


root = r'/home/linkx/autoware.1.13/src'

def recursion_dir_all_file(path):
    for dir_path, dirs, files in os.walk(path):
        for dir in dirs:
            if dir == "include":
                sub_path = os.path.join(dir_path,dir)
                print("\""+str(sub_path)+"/**\""+",")
            else:
                recursion_dir_all_file(os.path.join(path,dir))
            
    return


recursion_dir_all_file(root)
