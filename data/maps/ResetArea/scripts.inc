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
	msgbox ResetArea_RareCandySoruce_Text_1
	additem ITEM_CANDY_BAG, 1
	msgbox ResetArea_RareCandySoruce_Text_2
	additem ITEM_MAX_REPEL, 99
	msgbox ResetArea_RareCandySoruce_Text_3
	compare VAR_BIRCH_LAB_STATE, BIRCH_LAB_STATE_RECEIVED_POKEDEX
	goto_if_eq ResetArea_RareCandySoruce_2
	msgbox ResetArea_RareCandySoruce_Text_5
ResetArea_RareCandySoruce_1:
	releaseall
	return

ResetArea_RareCandySoruce_2:
	additem ITEM_MASTER_BALL, 99
	msgbox ResetArea_RareCandySoruce_Text_4
	goto ResetArea_RareCandySoruce_1


ResetArea_BuyStarterSet2::
	lockall
	compare VAR_ACHIEVEMENT_POINTS, STARTER_SET_2_UNLOCK_AMOUNT
	goto_if_ge ResetArea_BuyStarterSet2_3
ResetArea_BuyStarterSet2_2:
	compare VAR_ACHIEVEMENT_POINTS, STARTER_SET_2_UNLOCK_AMOUNT
	goto_if_lt ResetArea_BuyStarterSet2_10
ResetArea_BuyStarterSet2_8:
	goto_if_set FLAG_STARTER_SET_2_UNLOCK, ResetArea_BuyStarterSet2_13
	return

ResetArea_BuyStarterSet2_1:
	buffernumberstring STR_VAR_1, STARTER_SET_2_UNLOCK_AMOUNT
	msgbox ResetArea_BuyStarterSet2_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq ResetArea_BuyStarterSet2_6
	return

ResetArea_BuyStarterSet2_3:
	goto_if_unset FLAG_STARTER_SET_2_UNLOCK, ResetArea_BuyStarterSet2_1
	goto ResetArea_BuyStarterSet2_2

ResetArea_BuyStarterSet2_6:
	subvar VAR_ACHIEVEMENT_POINTS, 50
	setflag FLAG_STARTER_SET_2_UNLOCK
	setvar VAR_STARTER_SET, STARTER_SET_2
	releaseall
	return

ResetArea_BuyStarterSet2_9:
	msgbox ResetArea_BuyStarterSet2_Text_1
	releaseall
	goto ResetArea_BuyStarterSet2_8

ResetArea_BuyStarterSet2_10:
	goto_if_unset FLAG_STARTER_SET_2_UNLOCK, ResetArea_BuyStarterSet2_9
	goto ResetArea_BuyStarterSet2_8

ResetArea_BuyStarterSet2_13:
	msgbox ResetArea_BuyStarterSet2_Text_2
	msgbox ResetArea_BuyStarterSet2_Text_3, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq ResetArea_BuyStarterSet2_16
ResetArea_BuyStarterSet2_15:
	releaseall
	return

ResetArea_BuyStarterSet2_16:
	compare VAR_STARTER_SET, STARTER_SET_1
	goto_if_eq ResetArea_BuyStarterSet2_18
	compare VAR_STARTER_SET, STARTER_SET_2
	goto_if_eq ResetArea_BuyStarterSet2_19
	goto ResetArea_BuyStarterSet2_15

ResetArea_BuyStarterSet2_18:
	setvar VAR_STARTER_SET, STARTER_SET_2
	msgbox ResetArea_BuyStarterSet2_Text_4
	goto ResetArea_BuyStarterSet2_15

ResetArea_BuyStarterSet2_19:
	setvar VAR_STARTER_SET, STARTER_SET_1
	msgbox ResetArea_BuyStarterSet2_Text_5
	goto ResetArea_BuyStarterSet2_15


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
	.string "Here are some useful items$"

ResetArea_RareCandySoruce_Text_1:
	.string "given rare candies$"

ResetArea_RareCandySoruce_Text_2:
	.string "given candy bag$"

ResetArea_RareCandySoruce_Text_3:
	.string "given max repels$"

ResetArea_RareCandySoruce_Text_4:
	.string "given master balls$"

ResetArea_RareCandySoruce_Text_5:
	.string "come back later for master balls$"

ResetArea_BuyStarterSet2_Text_0:
	.string "Spend {STR_VAR_1} points to unlock new starter set?$"

ResetArea_BuyStarterSet2_Text_1:
	.string "You don't have enough points$"

ResetArea_BuyStarterSet2_Text_2:
	.string "You've already unlocked this$"

ResetArea_BuyStarterSet2_Text_3:
	.string "Would you like to swap between starter sets?$"

ResetArea_BuyStarterSet2_Text_4:
	.string "Starter set switched to set 2.$"

ResetArea_BuyStarterSet2_Text_5:
	.string "Starter set switched to set 1.$"
