#include <gtkmm.h>
#include <exception>
#include <iostream>

class MyWindow : public Gtk::Window
{
    public:
        MyWindow();
};


int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create("org.gtkmm.examples.base");
    auto refBuilder = Gtk::Builder::create();
    Gtk::Window* pWindow = nullptr;
    try
    {
        refBuilder->add_from_file("../gtk_assets/gtk_test.glade");
    }
    catch(const Glib::FileError& ex)
    {
        std::cerr << "FileError: " << ex.what() << std::endl;
        return 1;
    }
    catch(const Glib::MarkupError& ex)
    {
        std::cerr << "MarkupError: " << ex.what() << std::endl;
        return 1;
    }
    catch(const Gtk::BuilderError& ex)
    {
        std::cerr << "BuilderError: " << ex.what() << std::endl;
        return 1;
    }


    refBuilder->get_widget("test_window", pWindow);

    // pWindow->set_default_size(200, 200);

    app->run(*pWindow);

    delete pWindow;
    pWindow = nullptr;

    return 0;





    // window.set_default_size(200, 200);

    // return app->run(window);
}