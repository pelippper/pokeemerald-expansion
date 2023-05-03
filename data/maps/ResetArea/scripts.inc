ResetArea_MapScripts::
	.byte 0


ResetArea_SelectBonus::
	lockall
	buffernumberstring STR_VAR_1, VAR_ACHIEVEMENT_POINTS
	msgbox ResetArea_SelectBonus_Text_0
	releaseall
	return


ResetArea_GainPointDebug::
	lockall
	addvar VAR_ACHIEVEMENT_POINTS, 1
	buffernumberstring STR_VAR_1, VAR_ACHIEVEMENT_POINTS
	msgbox ResetArea_GainPointDebug_Text_0
	msgbox ResetArea_GainPointDebug_Text_1
	releaseall
	return


ResetArea_ResetPoints::
	lockall
	msgbox ResetArea_ResetPoints_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq ResetArea_ResetPoints_2
ResetArea_ResetPoints_1:
	releaseall
	return

ResetArea_ResetPoints_2:
	setvar VAR_ACHIEVEMENT_POINTS, 0
	msgbox ResetArea_ResetPoints_Text_1
	goto ResetArea_ResetPoints_1


ResetArea_RareCandySoruce::
	lockall
	msgbox ResetArea_RareCandySoruce_Text_0
	additem ITEM_RARE_CANDY, 99
	releaseall
	return


ResetArea_SelectBonus_Text_0:
	.string "You have {STR_VAR_1} reset points.$"

ResetArea_GainPointDebug_Text_0:
	.string "One point added.$"

ResetArea_GainPointDebug_Text_1:
	.string "You now have {STR_VAR_1} reset points.$"

ResetArea_ResetPoints_Text_0:
	.string "Would you like to reset your achievement points?$"

ResetArea_ResetPoints_Text_1:
	.string "Points reset.$"

ResetArea_RareCandySoruce_Text_0:
	.string "Here are some rare candies$"
