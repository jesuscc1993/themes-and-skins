[Variables]
; General
hoverColor 					= 255, 255, 255, 255
regularColor				= 200, 200, 200, 255
backgroundColor			= 16,   16,  16, 255

[Rainmeter]
Update = -1
ContextTitle  			= Setup Games
ContextAction  			= ["#CONFIGEDITOR#" "#CURRENTPATH#\gamePaths.inc"]
ContextTitle2 			= ----
ContextTitle3 			= Refresh skin
ContextAction3  		= !Refresh
ContextTitle4 			= ----
ContextTitle5 			= Skin settings
ContextAction5 			= [!SkinMenu]
RightMouseUpAction 	= [!SkinCustomMenu]

[GameCover]
W                   = #cellWidth#
H                   = #cellHeight#
SolidColor          = #backgroundColor#
ImageTint           = #regularColor#
MouseOverAction     = [!SetOption #CURRENTSECTION# ImageTint "#hoverColor#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction    = [!SetOption #CURRENTSECTION# ImageTint "#regularColor#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction   = ["#Target#"]
Solid               = 1