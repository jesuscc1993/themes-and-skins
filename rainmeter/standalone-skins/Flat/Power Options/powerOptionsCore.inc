[Metadata]
Version = 1.0.0
Description = Provides an icon with a contextual menu containing all power options
Author = MetalTxus
License = Creative Commons BY-NC 3.0

[Rainmeter]
Update = -1
ContextTitle = Sign Out
ContextAction = #SignOut#
ContextTitle2 = Lock
ContextAction2 = #Lock#
ContextTitle3 = ----
ContextTitle4 = Sleep
ContextAction4 = #Sleep#
ContextTitle5 = Hibernate
ContextAction5 = #Hibernate#
ContextTitle6 = Shutdown
ContextAction6 = #Shutdown#
ContextTitle7 = ----
ContextTitle8 = Restart
ContextAction8 = #Restart#
ContextTitle9 = ----
ContextTitle10 = Skin settings
ContextAction10 = [!SkinMenu]

[Variables]
SignOut = shutdown /l
Lock = rundll32.exe user32.dll LockWorkStation
Sleep = rundll32.exe PowrProf.dll, SetSuspendState 0, 1, 0
Hibernate = shutdown /h
Shutdown = shutdown /p
Restart = shutdown /r