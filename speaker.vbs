Set args =Wscript.Arguments
Dim message,Speak
Set Speak=CreateObject("sapi.spvoice")
For Each arg in args
Speak.Speak arg
Next