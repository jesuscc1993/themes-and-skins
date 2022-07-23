; Player name list available at http:\\docs.rainmeter.net\manual\plugins\nowplaying#playerlist

[Variables]
Update = 250
MouseLeaveAction = #HideDataContent#
MiddleMouseUpAction = #OpenPlayer#
DataContentAlpha = 0
DataContentAlphaAction = [!UpdateMeasure "DataContentAlphaTimer"][!UpdateMeterGroup "DataContent"][!Redraw]
ShowDataContent = [!CommandMeasure DataContentAlphaTimer "Execute 1"][!Update]
HideDataContent = [!CommandMeasure DataContentAlphaTimer "Execute 2"][!Update]
ShowControls = [!ShowMeterGroup PlayContent]
HideControls = [!HideMeterGroup PlayContent]
OpenPlayer = [!CommandMeasure mediaPlayer "OpenPlayer"]
TogglePlay = [!CommandMeasure mediaPlayer "PlayPause"]
PlayPrevious = [!CommandMeasure mediaPlayer "Previous"]
PlayNext = [!CommandMeasure mediaPlayer "Next"]

[Rainmeter]
Update = 250
MouseLeaveAction = #HideDataContent#
MiddleMouseUpAction = #OpenPlayer#
ContextTitle = Open Media Player
ContextAction = [!CommandMeasure mediaPlayer "OpenPlayer"]
ContextTitle2 = Play / Pause
ContextAction2 = [!CommandMeasure mediaPlayer "PlayPause"]
ContextTitle3 = Next song
ContextAction3 = [!CommandMeasure mediaPlayer "Next"]
ContextTitle4 = Previous song
ContextAction4 = [!CommandMeasure mediaPlayer "Previous"]

[DataContentAlphaTimer]
Measure = Plugin
Plugin = ActionTimer
ActionList1 = Repeat FadeIn, 10, 10
FadeIn = [!SetVariable DataContentAlpha "(Clamp(#DataContentAlpha# +26, 0, 255))"]#DataContentAlphaAction#
ActionList2 = Repeat FadeOut, 10, 10
FadeOut = [!SetVariable DataContentAlpha "(Clamp(#DataContentAlpha# -26, 0, 255))"]#DataContentAlphaAction#
DynamicVariables = 1



[mediaPlayer]
Measure = Plugin
Plugin = NowPlaying.dll
PlayerName = #PlayerName#
PlayerType = Title
OnChangeAction=[!UpdateMeasure "mediaProgress"][!UpdateMeasure "mediaArtist"][!UpdateMeasure "mediaCover"][!UpdateMeasure "mediaState"][!UpdateMeterGroup "TopContent"][!Redraw]

[mediaProgress]
Measure = Plugin
Plugin = NowPlaying.dll
PlayerName = [mediaPlayer]
PlayerType = Progress

[mediaArtist]
Measure = Plugin
Plugin = NowPlaying.dll
PlayerName = [mediaPlayer]
PlayerType = Artist

[mediaCover]
Measure = Plugin
Plugin = NowPlaying.dll
PlayerName = [mediaPlayer]
PlayerType = Cover
Substitute = "":"#@#player\noCover.gif"

[mediaVolume]
Measure = Plugin
Plugin = NowPlaying.dll
PlayerName = [mediaPlayer]
PlayerType = Volume

[mediaState]
Measure = Plugin
Plugin = NowPlaying.dll
PlayerName = #PlayerName#
PlayerType = State
Substitute = "0":"play.png", "1":"pause.png", "2":"play.png"
IfBelowValue=1
IfBelowAction=[!SetOption ControlsBackground MouseOverAction ""][!SetOption PlayButton LeftMouseUpAction """#OpenPlayer#"""]#HideDataContent##HideControls#
IfAboveValue=0
IfAboveAction=[!SetOption ControlsBackground MouseOverAction """#ShowDataContent#"""][!SetOption PlayButton LeftMouseUpAction """#TogglePlay#"""]#ShowControls#