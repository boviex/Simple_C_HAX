#include "FreeSelect.h"

static int SumOnSelect(struct FSProc* proc, int x, int y);
static int SumOnCancel(struct FSProc* proc, int x, int y);

static const struct FSDefinition sSummonFSD = {
	.onAPress = SumOnSelect,
	.onBPress = SumOnCancel,
};

void SumStartPosSelection(void) {
	StartFreeSelection(&sSummonFSD);
}

static int SumOnSelect(struct FSProc* proc, int x, int y) {
	Font_ResetAllocation();
	HideMoveRangeGraphics();
	EndBottomHelpText();

	gActionData.xOther = x;
	gActionData.yOther = y;

	gActionData.actionIndex = UNIT_ACTION_SUMMON;

	EnsureCameraOntoPosition(
		(Proc*)(proc),

		gActiveUnit->xPos,
		gActiveUnit->yPos
	);

	return FS_END | FS_SND_BEEP;
}

static int SumOnCancel(struct FSProc* proc, int x, int y) {
	Font_ResetAllocation();
	HideMoveRangeGraphics();
	EndBottomHelpText();

	SetCursorMapPosition(
		gActiveUnit->xPos,
		gActiveUnit->yPos
	);

	StartProc(gProc_GoBackToUnitMenu, ROOT_PROC_3);

	return FS_END | FS_SND_BOOP;
}
