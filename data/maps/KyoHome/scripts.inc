# 1 "data/maps/KyoHome/scripts.pory"

# 2 "data/maps/KyoHome/scripts.pory"
KyoHome_MapScripts::
# 3 "data/maps/KyoHome/scripts.pory"
	.byte 0

KyoHome_ProgessJournal::
# 7 "data/maps/KyoHome/scripts.pory"
	lockall
# 8 "data/maps/KyoHome/scripts.pory"
	msgbox JournalText
# 9 "data/maps/KyoHome/scripts.pory"
	releaseall
	return


KyoHome_BringWhimsi::
# 20 "data/maps/KyoHome/scripts.pory"
	lockall
# 21 "data/maps/KyoHome/scripts.pory"
	showmonpic SPECIES_WHIMSICOTT, 10, 3
# 22 "data/maps/KyoHome/scripts.pory"
	waitmoncry
# 23 "data/maps/KyoHome/scripts.pory"
	msgbox KyoHome_BringWhimsi_Text_0, MSGBOX_YESNO
# 24 "data/maps/KyoHome/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq KyoHome_BringWhimsi_2
# 46 "data/maps/KyoHome/scripts.pory"
	hidemonpic
# 47 "data/maps/KyoHome/scripts.pory"
	msgbox Whimsi_Denied
KyoHome_BringWhimsi_1:
# 49 "data/maps/KyoHome/scripts.pory"
	waitmessage
# 50 "data/maps/KyoHome/scripts.pory"
	releaseall
	end

KyoHome_BringWhimsi_2:
# 25 "data/maps/KyoHome/scripts.pory"
	givemon SPECIES_WHIMSICOTT, 50, ITEM_MASTER_BALL
# 26 "data/maps/KyoHome/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq KyoHome_BringWhimsi_5
# 33 "data/maps/KyoHome/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq KyoHome_BringWhimsi_6
# 41 "data/maps/KyoHome/scripts.pory"
	hidemonpic
# 42 "data/maps/KyoHome/scripts.pory"
	msgbox KyoHome_BringWhimsi_Text_2
	goto KyoHome_BringWhimsi_1

KyoHome_BringWhimsi_5:
# 27 "data/maps/KyoHome/scripts.pory"
	playfanfare MUS_EVOLVED
# 28 "data/maps/KyoHome/scripts.pory"
	msgbox KyoHome_BringWhimsi_Text_1
# 29 "data/maps/KyoHome/scripts.pory"
	removeobject 1
# 30 "data/maps/KyoHome/scripts.pory"
	setflag FLAG_UNUSED_0x020
# 31 "data/maps/KyoHome/scripts.pory"
	call NicknamePartyMon
	goto KyoHome_BringWhimsi_1

KyoHome_BringWhimsi_6:
# 34 "data/maps/KyoHome/scripts.pory"
	playfanfare MUS_EVOLVED
# 35 "data/maps/KyoHome/scripts.pory"
	msgbox KyoHome_BringWhimsi_Text_1
# 36 "data/maps/KyoHome/scripts.pory"
	removeobject 1
# 37 "data/maps/KyoHome/scripts.pory"
	setflag FLAG_UNUSED_0x020
# 38 "data/maps/KyoHome/scripts.pory"
	call NicknameBoxMon
	goto KyoHome_BringWhimsi_1


NicknamePartyMon::
# 57 "data/maps/KyoHome/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 58 "data/maps/KyoHome/scripts.pory"
	hidemonpic
# 59 "data/maps/KyoHome/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknamePartyMon_1
	return

NicknamePartyMon_1:
# 60 "data/maps/KyoHome/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 61 "data/maps/KyoHome/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	return


NicknameBoxMon::
# 69 "data/maps/KyoHome/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 70 "data/maps/KyoHome/scripts.pory"
	hidemonpic
# 71 "data/maps/KyoHome/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknameBoxMon_2
NicknameBoxMon_1:
# 74 "data/maps/KyoHome/scripts.pory"
	call Common_EventScript_TransferredToPC
	return

NicknameBoxMon_2:
# 72 "data/maps/KyoHome/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
	goto NicknameBoxMon_1


KyoHome_BringWhimsi_Text_0:
# 23 "data/maps/KyoHome/scripts.pory"
	.string "Whimsicott seems happy to see you!\p Would you like to bring it along?$"

KyoHome_BringWhimsi_Text_1:
# 28 "data/maps/KyoHome/scripts.pory"
	.string "Whimsicott joined you!$"

KyoHome_BringWhimsi_Text_2:
# 42 "data/maps/KyoHome/scripts.pory"
	.string "No More Room$"

NicknamePartyMon_Text_0:
# 57 "data/maps/KyoHome/scripts.pory"
	.string "Give it a nickname?$"

JournalText::
# 12 "data/maps/KyoHome/scripts.pory"
	.string "I finally got working text and\n"
	.string "graphics...\p"
	.string "Maybe?\p"
	.string "It depends on if the player sprites and\n"
	.string "my boi Whimsicott looks different.\p"
	.string "Next, I'll work on a FULLY CUSTOM map.\n"
	.string "That might be fun.\p"
	.string "Or not.$"

Whimsi_Denied::
# 78 "data/maps/KyoHome/scripts.pory"
	.string "Whimsicott is dishearted but\n"
	.string "understands your decision.$"
