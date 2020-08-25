import os
import requests

def uptest(name, size, path):
    #login
    usn = "mdptit"
    pwd = "itptit"
    payload = {'login_user':usn,'password':pwd}
    sess = requests.session()
    r = sess.post("https://www.spoj.com/login",data=payload)
    #up test
    url = "https://www.spoj.com/problems/P191PRO" + name + "/edit/"
    print ("Dang up test bai: P191PRO" + name)
    for i in range(size):
        nameIn = path + "/" + str(i + 1) + ".in"
        nameOut = path + "/" + str(i + 1) + ".out"
        fin = open(nameIn,'rb')
        fout = open(nameOut, 'rb')
        data = {
            "form_action" : "modify_new_testcase",
            "upload" : "upload",
            "testcase" : str(i + 1),
            "in_act" : "w",
            "out_act" : "w",
            "timelimit" : "1",
            "judge" : "1",
            "judge_c" : "0",
            "judge_file" : "", 
            "dos2unix" : "on", 
            "Upload" : "Upload"
        }
        files = {"in_file" : fin, "out_file" : fout}
        r = sess.post(url, data = data, files = files)
        print ("-> Up test", str(i + 1))
###################################################################
def count(path) :
    res = 0
    files = os.listdir(path)
    for file in files:
        if len(file.split('.')) == 2 and file.split('.')[1] == "in":
            res = res + 1
    return res
####################################################################
root =  os.getcwd()
folders = os.listdir(root)
for folder in folders:
    if len(folder) == 1 and folder >= "A" and folder <= "Z":
        paths = root + "\\" + folder
        files = os.listdir(paths)
        for file in files: 
            if file.lower() == "test":
                path = paths + "\\" + file
                size = count(path)
                name = folder
                uptest(name, size, path)
                print ("Up thanh cong bai:", name)
print ("Xong!!!")
                
