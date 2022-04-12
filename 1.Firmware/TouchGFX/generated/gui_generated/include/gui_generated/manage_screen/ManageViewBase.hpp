/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef MANAGEVIEWBASE_HPP
#define MANAGEVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/manage_screen/ManagePresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/mixins/ClickListener.hpp>
#include <touchgfx/EasingEquations.hpp>
#include <touchgfx/mixins/FadeAnimator.hpp>

class ManageViewBase : public touchgfx::View<ManagePresenter>
{
public:
    ManageViewBase();
    virtual ~ManageViewBase() {}
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void increaseValue()
    {
        // Override and implement this function in Manage
    }

    virtual void decreaseValue()
    {
        // Override and implement this function in Manage
    }

    virtual void increaseValue1()
    {
        // Override and implement this function in Manage
    }

    virtual void decreaseValue1()
    {
        // Override and implement this function in Manage
    }

    virtual void increaseValue2()
    {
        // Override and implement this function in Manage
    }

    virtual void decreaseValue2()
    {
        // Override and implement this function in Manage
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box box1;
    touchgfx::FadeAnimator< touchgfx::ButtonWithLabel > buttonWithLabel1;
    touchgfx::ClickListener< touchgfx::BoxWithBorderButtonStyle< touchgfx::ToggleButtonTrigger > > flexButton1;
    touchgfx::TextAreaWithOneWildcard textArea1;
    touchgfx::IconButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::RepeatButtonTrigger > > flexButton1_1;
    touchgfx::IconButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::RepeatButtonTrigger > > flexButton1_2;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger > flexButton1_3;
    touchgfx::TextAreaWithOneWildcard textArea1_1;
    touchgfx::IconButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::RepeatButtonTrigger > > flexButton1_1_1;
    touchgfx::IconButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::RepeatButtonTrigger > > flexButton1_2_1;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger > flexButton1_4;
    touchgfx::TextAreaWithOneWildcard textArea1_2;
    touchgfx::IconButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::RepeatButtonTrigger > > flexButton1_1_2;
    touchgfx::IconButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::RepeatButtonTrigger > > flexButton1_2_2;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTAREA1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textArea1Buffer[TEXTAREA1_SIZE];
    static const uint16_t TEXTAREA1_1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textArea1_1Buffer[TEXTAREA1_1_SIZE];
    static const uint16_t TEXTAREA1_2_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textArea1_2Buffer[TEXTAREA1_2_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<ManageViewBase, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<ManageViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

};

#endif // MANAGEVIEWBASE_HPP
