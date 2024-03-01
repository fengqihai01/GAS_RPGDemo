// CopyRight FQH Demo


#include "UI/UserWidget/RPGUserWidget.h"

void URPGUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	OnWidgetControllerSet();
}
