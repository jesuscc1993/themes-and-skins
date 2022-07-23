[Variables]
@IncludeSettings = #@#settings.inc
GAME = .*"appid"(.*)"name"
ID = :(.*),"logo"
LOGO = (?siU).*"logo":"(.*)",
REGEX0_SUPED = (?siU)#GAME##GAME##GAME##GAME##GAME##GAME##GAME##GAME##GAME##GAME#

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
Measure = WebParser
Url = #steamURL#
RegExp = "#REGEX0_SUPED#"
FinishAction = [!Update "#CURRENTCONFIG#"]
UpdateRate = 60

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//AppID
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
[AppID1]
Measure = WebParser
Url = [GetGamesFirst]
RegExp = #ID#
StringIndex = 1
StringIndex2 = 1
Debug = 1
FinishAction = !Update "#CURRENTCONFIG#"
UpdateRate = 60

[AppID2]
Measure = WebParser
Url = [GetGamesFirst]
RegExp = #ID#
StringIndex = 2
StringIndex2 = 1
Debug = 1
FinishAction = !Update "#CURRENTCONFIG#"
UpdateRate = 60

[AppID3]
Measure = WebParser
Url = [GetGamesFirst]
RegExp = #ID#
StringIndex = 3
StringIndex2 = 1
Debug = 1
FinishAction = !Update "#CURRENTCONFIG#"
UpdateRate = 60

[AppID4]
Measure = WebParser
Url = [GetGamesFirst]
RegExp = #ID#
StringIndex = 4
StringIndex2 = 1
Debug = 1
FinishAction = !Update "#CURRENTCONFIG#"
UpdateRate = 60

[AppID5]
Measure = WebParser
Url = [GetGamesFirst]
RegExp = #ID#
StringIndex = 5
StringIndex2 = 1
Debug = 1
FinishAction = !Update "#CURRENTCONFIG#"
UpdateRate = 60

[AppID6]
Measure = WebParser
Url = [GetGamesFirst]
RegExp = #ID#
StringIndex = 6
StringIndex2 = 1
Debug = 1
FinishAction = !Update "#CURRENTCONFIG#"
UpdateRate = 60

[AppID7]
Measure = WebParser
Url = [GetGamesFirst]
RegExp = #ID#
StringIndex = 7
StringIndex2 = 1
Debug = 1
FinishAction = !Update "#CURRENTCONFIG#"
UpdateRate = 60

[AppID8]
Measure = WebParser
Url = [GetGamesFirst]
RegExp = #ID#
StringIndex = 8
StringIndex2 = 1
Debug = 1
FinishAction = !Update "#CURRENTCONFIG#"
UpdateRate = 60

[AppID9]
Measure = WebParser
Url = [GetGamesFirst]
RegExp = #ID#
StringIndex = 9
StringIndex2 = 1
Debug = 1
FinishAction = !Update "#CURRENTCONFIG#"
UpdateRate = 60

[AppID10]
Measure = WebParser
Url = [GetGamesFirst]
RegExp = #ID#
StringIndex = 10
StringIndex2 = 1
Debug = 1
FinishAction = !Update "#CURRENTCONFIG#"
UpdateRate = 60

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Image URL
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
[Pic1]
Measure = WebParser
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
Measure = WebParser
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
Measure = WebParser
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
Measure = WebParser
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
Measure = WebParser
Url = [GetGamesFirst]
RegExp = #LOGO#
Substitute = "\\\/":"/","steamcommunity\/public\/images":"steam","\w*\.jpg":"header.jpg"
RegExpSubstitute = 1
StringIndex = 5
StringIndex2 = 1
FinishAction = [!EnableMeasure 5Pic][!SetOption 5Pic URL [Pic5]][!CommandMeasure 5Pic "Update"]
DynamicVariables = 1
UpdateRate = 60

[Pic6]
Measure = WebParser
Url = [GetGamesFirst]
RegExp = #LOGO#
Substitute = "\\\/":"/","steamcommunity\/public\/images":"steam","\w*\.jpg":"header.jpg"
RegExpSubstitute = 1
StringIndex = 6
StringIndex2 = 1
FinishAction = [!EnableMeasure 6Pic][!SetOption 6Pic URL [Pic6]][!CommandMeasure 6Pic "Update"]
DynamicVariables = 1
UpdateRate = 60

[Pic7]
Measure = WebParser
Url = [GetGamesFirst]
RegExp = #LOGO#
Substitute = "\\\/":"/","steamcommunity\/public\/images":"steam","\w*\.jpg":"header.jpg"
RegExpSubstitute = 1
StringIndex = 7
StringIndex2 = 1
FinishAction = [!EnableMeasure 7Pic][!SetOption 7Pic URL [Pic7]][!CommandMeasure 7Pic "Update"]
DynamicVariables = 1
UpdateRate = 60

[Pic8]
Measure = WebParser
Url = [GetGamesFirst]
RegExp = #LOGO#
Substitute = "\\\/":"/","steamcommunity\/public\/images":"steam","\w*\.jpg":"header.jpg"
RegExpSubstitute = 1
StringIndex = 8
StringIndex2 = 1
FinishAction = [!EnableMeasure 8Pic][!SetOption 8Pic URL [Pic8]][!CommandMeasure 8Pic "Update"]
DynamicVariables = 1
UpdateRate = 60

[Pic9]
Measure = WebParser
Url = [GetGamesFirst]
RegExp = #LOGO#
Substitute = "\\\/":"/","steamcommunity\/public\/images":"steam","\w*\.jpg":"header.jpg"
RegExpSubstitute = 1
StringIndex = 9
StringIndex2 = 1
FinishAction = [!EnableMeasure 9Pic][!SetOption 9Pic URL [Pic9]][!CommandMeasure 9Pic "Update"]
DynamicVariables = 1
UpdateRate = 60

[Pic10]
Measure = WebParser
Url = [GetGamesFirst]
RegExp = #LOGO#
Substitute = "\\\/":"/","steamcommunity\/public\/images":"steam","\w*\.jpg":"header.jpg"
RegExpSubstitute = 1
StringIndex = 10
StringIndex2 = 1
FinishAction = [!EnableMeasure 10Pic][!SetOption 10Pic URL [Pic10]][!CommandMeasure 10Pic "Update"]
DynamicVariables = 1
UpdateRate = 60

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Image Download
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
[1Pic]
Measure = WebParser
Download = 1
DynamicVariables = 1
Disabled = 1

[2Pic]
Measure = WebParser
Download = 1
DynamicVariables = 1
Disabled = 1

[3Pic]
Measure = WebParser
Download = 1
DynamicVariables = 1
Disabled = 1

[4Pic]
Measure = WebParser
Download = 1
DynamicVariables = 1
Disabled = 1

[5Pic]
Measure = WebParser
Download = 1
DynamicVariables = 1
Disabled = 1

[6Pic]
Measure = WebParser
Download = 1
DynamicVariables = 1
Disabled = 1

[7Pic]
Measure = WebParser
Download = 1
DynamicVariables = 1
Disabled = 1

[8Pic]
Measure = WebParser
Download = 1
DynamicVariables = 1
Disabled = 1

[9Pic]
Measure = WebParser
Download = 1
DynamicVariables = 1
Disabled = 1

[10Pic]
Measure = WebParser
Download = 1
DynamicVariables = 1
Disabled = 1