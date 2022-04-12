/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/main_screen/MainViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>


MainViewBase::MainViewBase() :
    buttonCallback(this, &MainViewBase::buttonCallbackHandler)
{

    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    swipeContainer1.setXY(0, 0);
    swipeContainer1.setPageIndicatorXY(0, 0);
    swipeContainer1.setSwipeCutoff(50);
    swipeContainer1.setEndSwipeElasticWidth(50);

    swipeContainer1Page1.setWidth(480);
    swipeContainer1Page1.setHeight(272);

    box1.setPosition(0, 0, 480, 272);
    box1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    swipeContainer1Page1.add(box1);

    circle2.setPosition(179, 0, 441, 365);
    circle2.setCenter(260, 260);
    circle2.setRadius(260);
    circle2.setLineWidth(0);
    circle2.setArc(0, 360);
    circle2Painter.setColor(touchgfx::Color::getColorFromRGB(240, 46, 46));
    circle2.setPainter(circle2Painter);
    circle2.setAlpha(208);
    swipeContainer1Page1.add(circle2);

    circle1.setPosition(0, 0, 480, 272);
    circle1.setCenter(40, 40);
    circle1.setRadius(240);
    circle1.setLineWidth(0);
    circle1.setArc(0, 360);
    circle1Painter.setColor(touchgfx::Color::getColorFromRGB(61, 134, 217));
    circle1.setPainter(circle1Painter);
    circle1.setAlpha(247);
    swipeContainer1Page1.add(circle1);

    circle3.setPosition(0, 133, 352, 163);
    circle3.setCenter(100, 200);
    circle3.setRadius(205);
    circle3.setLineWidth(0);
    circle3.setArc(0, 360);
    circle3Painter.setColor(touchgfx::Color::getColorFromRGB(33, 153, 9));
    circle3.setPainter(circle3Painter);
    swipeContainer1Page1.add(circle3);

    textArea2.setXY(319, 133);
    textArea2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea2.setLinespacing(0);
    Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_93MQ).getText());
    textArea2.setWildcard(textArea2Buffer);
    textArea2.resizeToCurrentText();
    textArea2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_TOCP));
    swipeContainer1Page1.add(textArea2);

    textArea1.setXY(36, 52);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea1.setLinespacing(0);
    Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_V8EO).getText());
    textArea1.setWildcard(textArea1Buffer);
    textArea1.resizeToCurrentText();
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_CWS1));
    swipeContainer1Page1.add(textArea1);

    textArea3.setXY(36, 189);
    textArea3.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea3.setLinespacing(0);
    Unicode::snprintf(textArea3Buffer, TEXTAREA3_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_OS4B).getText());
    textArea3.setWildcard(textArea3Buffer);
    textArea3.resizeToCurrentText();
    textArea3.setTypedText(touchgfx::TypedText(T___SINGLEUSE_S3AT));
    swipeContainer1Page1.add(textArea3);
    swipeContainer1.add(swipeContainer1Page1);

    swipeContainer1Page2.setWidth(480);
    swipeContainer1Page2.setHeight(272);

    box2_1.setPosition(0, 0, 480, 272);
    box2_1.setColor(touchgfx::Color::getColorFromRGB(25, 93, 181));
    swipeContainer1Page2.add(box2_1);

    buttonWithLabel1_1.setXY(36, 76);
    buttonWithLabel1_1.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    buttonWithLabel1_1.setLabelText(touchgfx::TypedText(T___SINGLEUSE_9KO6));
    buttonWithLabel1_1.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel1_1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel1_1.setAction(buttonCallback);
    swipeContainer1Page2.add(buttonWithLabel1_1);

    buttonWithLabel3_1.setXY(277, 76);
    buttonWithLabel3_1.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    buttonWithLabel3_1.setLabelText(touchgfx::TypedText(T___SINGLEUSE_72WW));
    buttonWithLabel3_1.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel3_1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel3_1.setAction(buttonCallback);
    swipeContainer1Page2.add(buttonWithLabel3_1);

    buttonWithLabel4_1.setXY(277, 159);
    buttonWithLabel4_1.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    buttonWithLabel4_1.setLabelText(touchgfx::TypedText(T___SINGLEUSE_JZBP));
    buttonWithLabel4_1.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel4_1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    swipeContainer1Page2.add(buttonWithLabel4_1);

    buttonWithLabel2_1.setXY(36, 159);
    buttonWithLabel2_1.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    buttonWithLabel2_1.setLabelText(touchgfx::TypedText(T___SINGLEUSE_9B0J));
    buttonWithLabel2_1.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel2_1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    swipeContainer1Page2.add(buttonWithLabel2_1);
    swipeContainer1.add(swipeContainer1Page2);
    swipeContainer1.setSelectedPage(0);

    add(__background);
    add(swipeContainer1);
}

void MainViewBase::setupScreen()
{

}

void MainViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonWithLabel1_1)
    {
        //Interaction1
        //When buttonWithLabel1_1 clicked change screen to Manage
        //Go to Manage with screen transition towards East
        application().gotoManageScreenWipeTransitionEast();
    }
    else if (&src == &buttonWithLabel3_1)
    {
        //Interaction2
        //When buttonWithLabel3_1 clicked change screen to Details
        //Go to Details with screen transition towards East
        application().gotoDetailsScreenWipeTransitionEast();
    }
}
