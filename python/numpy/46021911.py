# from https://stackoverflow.com/questions/46021911

import sys, os
import time
import wx
import traceback
from textwrap import wrap
import shutil
import itertools
import numpy as np
import matplotlib
matplotlib.use('WX')
import matplotlib.pyplot as plt

import threading

def test():
    Do = Data()    
    Do.PlotGraph()

class Data(object):
    def __init__(self):       
        self.SavePath = "/Users/luccary/Downloads/foo/"

    def f(self, t):
        return np.exp(-t) * np.cos(2*np.pi*t)

    def PlotGraph(self):
        #Plotting
        print "***** Generating plot"
        t1 = np.arange(0.0, 5.0, 0.1)
        t2 = np.arange(0.0, 5.0, 0.02)

        print "Initialize subplots"
        fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(nrows=2, ncols=2, frameon=False, figsize=(20, 10))
        fontSize = 13

        print "Creating ax1"
        ax1title = "ax1" 
        ax1.set_title(ax1title, fontsize = fontSize)
        ax1.plot(t1, self.f(t1), 'bo', t2, self.f(t2), 'k')    

        print "Creating ax2"      
        ax2title = "ax2" 
        ax2.set_title(ax2title, fontsize = fontSize)
        ax2.plot(t1, self.f(t1), 'bo', t2, self.f(t2), 'k')

        print "Creating ax3"
        ax3title = "ax3" 
        ax3.set_title(ax3title, fontsize = fontSize)
        ax3.plot(t1, self.f(t1), 'bo', t2, self.f(t2), 'k')

        print "Creating ax4"
        ax4title = "ax4" 
        ax4.set_title(ax4title, fontsize = fontSize)
        ax4.plot(t1, self.f(t1), 'bo', t2, self.f(t2), 'k')

        fig.subplots_adjust(hspace = 0.35) #make room for axes title and x-axis label
        fig.subplots_adjust(bottom = 0.07) #make room for axes title and x-axis label
        fig.subplots_adjust(wspace = 0.30)
        fig.subplots_adjust(top = .86)

        filename= "Test"

        if not os.path.exists(self.SavePath):
            os.makedirs(self.SavePath)

        savefilename = self.unique_file(self.SavePath, filename, "png")        
        print "***** Saving plot to: " + self.SavePath + savefilename        
        fig.savefig(self.SavePath + savefilename, dpi = 200)
        plt.close(fig)

    def unique_file(self, path, basename, ext):
        actualname = "%s.%s" % (basename, ext)
        c = itertools.count()
        while os.path.exists(path + actualname):
            actualname = "%s_[%d].%s" % (basename, next(c), ext)
            #print "actualname: " + actualname
        return actualname 


################## THREAD UPDATE GUI ######################
#1. Create new custom event to update the display
DisplayEventType = wx.NewEventType();
EVT_DISPLAY = wx.PyEventBinder(DisplayEventType, 1);

def GetDataThreadStart(window):
    GetDataThread(window)

class GetDataThread(threading.Thread):    
    def __init__(self, output_window):
        threading.Thread.__init__(self)
        self.output_window = output_window
        print "Thread started"        
        self.start()

    def run(self):
        test()
        print "Test Done\n\n"
        self.UpdateFunction("Enable Go Button")     

    def UpdateFunction(self, msg):
        evt = UpdateDisplayEvent(DisplayEventType, -1) #initialize update display event
        evt.UpdateText(str(msg));  #update display event
        wx.PostEvent(self.output_window, evt)   

#Define event
class UpdateDisplayEvent(wx.PyCommandEvent):    
    def __init__(self, evtType, id):
        wx.PyCommandEvent.__init__(self, evtType, id)
        self.msg = ""  

    def UpdateText(self,text):
        self.msg = text

    def GetText(self):
        return self.msg


######## Define GUI ###########
class MyPanel(wx.Panel):
    def __init__(self, parent):
        wx.Panel.__init__(self, parent, -1)   

class MyFrame(wx.Frame):
    def __init__(self, parent):        
        self.title = 'Testing'
        wx.Frame.__init__(self, parent, -1, self.title, size = (300,350))                       

        pnl = MyPanel(self)                               

        self.Go_Button = wx.Button(pnl, -1, "Goooooo!")
        self.Bind(wx.EVT_BUTTON, self.ClickGo, self.Go_Button)       

        BoxSizerMain = wx.BoxSizer(wx.VERTICAL)      
        BoxSizerMain.Add(self.Go_Button, 0, wx.ALIGN_CENTER_HORIZONTAL)         
        self.Bind(EVT_DISPLAY, self.OnThreadUpdate)      

    def ClickGo(self, event):        
        self.Go_Button.Disable()
        GetDataThreadStart(self)           

    def OnThreadUpdate(self, event):
        msg = event.GetText()        
        if msg == "Enable Go Button":
            self.Go_Button.Enable()

def invokeGUI():
    app = wx.PySimpleApp()
    frame = MyFrame(None)
    frame.Show()
    frame.Iconize(True)
    frame.Iconize(False)
    frame.CenterOnScreen()
    app.MainLoop() 

if __name__ == '__main__':
    invokeGUI()
