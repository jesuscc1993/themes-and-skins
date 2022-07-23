[Variables]
@IncludeSettings = #@#settings.inc
GAME = .*"appid"(.*)"name"
ID = :(.*),"logo"
LOGO = (?siU).*"logo":"(.*)",
REGEX0_SUPED = (?siU)#GAME##GAME##GAME##GAME##GAME#

[GameCover]
MeasureName = #CURRENTSECTION#Pic
W = #coverWidth#
H = #coverHeight#
SolidColor = #backgroundColor#
ImageTint = #regularColor#
MouseOverAction = [!SetOption #CURRENTSECTION# ImageTint "#hoverColor#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction = [!SetOption #CURRENTSECTION# ImageTint "#regularColor#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction = [steam://rungameid/[AppID#CURRENTSECTION#]]
Solid = 1

[GetGamesFirst]
Measure = Plugin
Plugin = WebParser.dll
Url = #steamURL#
RegExp = "#REGEX0_SUPED#"
FinishAction = [!Update "#CURRENTCONFIG#"]
UpdateRate = 60

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//AppID
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
[AppID1]
Measure = Plugin
Plugin = WebParser.dll
Url = [GetGamesFirst]
RegExp = #ID#
StringIndex = 1
StringIndex2 = 1
Debug = 1
FinishAction = !Update "#CURRENTCONFIG#"
UpdateRate = 60

[AppID2]
Measure = Plugin
Plugin = WebParser.dll
Url = [GetGamesFirst]
RegExp = #ID#
StringIndex = 2
StringIndex2 = 1
Debug = 1
FinishAction = !Update "#CURRENTCONFIG#"
UpdateRate = 60

[AppID3]
Measure = Plugin
Plugin = WebParser.dll
Url = [GetGamesFirst]
RegExp = #ID#
StringIndex = 3
StringIndex2 = 1
Debug = 1
FinishAction = !Update "#CURRENTCONFIG#"
UpdateRate = 60

[AppID4]
Measure = Plugin
Plugin = WebParser.dll
Url = [GetGamesFirst]
RegExp = #ID#
StringIndex = 4
StringIndex2 = 1
Debug = 1
FinishAction = !Update "#CURRENTCONFIG#"
UpdateRate = 60

[AppID5]
Measure = Plugin
Plugin = WebParser.dll
Url = [GetGamesFirst]
RegExp = #ID#
StringIndex = 5
StringIndex2 = 1
Debug = 1
FinishAction = !Update "#CURRENTCONFIG#"
UpdateRate = 60

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Image URL
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
[Pic1]
Measure = Plugin
Plugin = WebParser.dll
Url = [GetGamesFirst]
RegExp = #LOGO#
Substitute = "\\\/":"/","steamcommunity\/public\/images":"steam","\w*\.jpg":"header.jpg"
RegExpSubstitute = 1
StringIndex = 1
StringIndex2 = 1
FinishAction = [!EnableMeasure 1Pic][!SetOption 1Pic URL [Pic1]][!CommandMeasure 1Pic "Update"]
DynamicVariables = 1
UpdateRate = 60

[Pic2]
Measure = Plugin
Plugin = WebParser.dll
Url = [GetGamesFirst]
RegExp = #LOGO#
Substitute = "\\\/":"/","steamcommunity\/public\/images":"steam","\w*\.jpg":"header.jpg"
RegExpSubstitute = 1
StringIndex = 2
StringIndex2 = 1
FinishAction = [!EnableMeasure 2Pic][!SetOption 2Pic URL [Pic2]][!CommandMeasure 2Pic "Update"]
DynamicVariables = 1
UpdateRate = 60

[Pic3]
Measure = Plugin
Plugin = WebParser.dll
Url = [GetGamesFirst]
RegExp = #LOGO#
Substitute = "\\\/":"/","steamcommunity\/public\/images":"steam","\w*\.jpg":"header.jpg"
RegExpSubstitute = 1
StringIndex = 3
StringIndex2 = 1
FinishAction = [!EnableMeasure 3Pic][!SetOption 3Pic URL [Pic3]][!CommandMeasure 3Pic "Update"]
DynamicVariables = 1
UpdateRate = 60

[Pic4]
Measure = Plugin
Plugin = WebParser.dll
Url = [GetGamesFirst]
RegExp = #LOGO#
Substitute = "\\\/":"/","steamcommunity\/public\/images":"steam","\w*\.jpg":"header.jpg"
RegExpSubstitute = 1
StringIndex = 4
StringIndex2 = 1
FinishAction = [!EnableMeasure 4Pic][!SetOption 4Pic URL [Pic4]][!CommandMeasure 4Pic "Update"]
DynamicVariables = 1
UpdateRate = 60

[Pic5]
Measure = Plugin
Plugin = WebParser.dll
Url = [GetGamesFirst]
RegExp = #LOGO#
Substitute = "\\\/":"/","steamcommunity\/public\/images":"steam","\w*\.jpg":"header.jpg"
RegExpSubstitute = 1
StringIndex = 5
StringIndex2 = 1
FinishAction = [!EnableMeasure 5Pic][!SetOption 5Pic URL [Pic5]][!CommandMeasure 5Pic "Update"]
DynamicVariables = 1
UpdateRate = 60

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Image Download
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
[1Pic]
Measure = Plugin
Plugin = WebParser.dll
Download = 1
DynamicVariables = 1
Disabled = 1

[2Pic]
Measure = Plugin
Plugin = WebParser.dll
Download = 1
DynamicVariables = 1
Disabled = 1

[3Pic]
Measure = Plugin
Plugin = WebParser.dll
Download = 1
DynamicVariables = 1
Disabled = 1

[4Pic]
Measure = Plugin
Plugin = WebParser.dll
Download = 1
DynamicVariables = 1
Disabled = 1

[5Pic]
Measure = Plugin
Plugin = WebParser.dll
Download = 1
DynamicVariables = 1
Disabled = 1
