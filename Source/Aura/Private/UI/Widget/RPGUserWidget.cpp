// CopyRight FQH Demo


#include "RPGUserWidget.h"


void URPGUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController=InWidgetController;
	OnWidgetControllerSet();
}
