import os
import shutil

img="D:/data/detail/val"
lab="D:/data/detail/valannot"

def reanme(img_path,lab_path):
    files=os.listdir(img_path)
    for i,file in enumerate(files):
        img=os.path.join(img_path,file)
        lab=os.path.join(lab_path,file)
        os.rename(img,os.path.join(img_path,'DJI_'+f'{i}'.rjust(4,'0')+'.png'))
        os.rename(lab,os.path.join(lab_path,'DJI_'+f'{i}'.rjust(4,'0')+'.png'))

reanme(img,lab)