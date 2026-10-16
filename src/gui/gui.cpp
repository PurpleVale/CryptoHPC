#include <gtkmm.h>
#include <iostream>

namespace {
  Gtk::Window* mainWindow = nullptr;

  Gtk::Button* addKeyButton = nullptr;
  Gtk::Button* encryptButton = nullptr;
  Gtk::Button* decryptButton = nullptr;
  Gtk::Button* saveRSAKeyButton = nullptr;
  Gtk::Button* saveDHKeyButton = nullptr;

  Gtk::ComboBoxText* encryptionMethodSelection = nullptr;

  Gtk::TextView* encryptText = nullptr;
  Gtk::TextView* decryptText = nullptr;

  Gtk::Entry* otherClientIPText = nullptr;

  Gtk::CheckButton* bitLengthButton512 = nullptr;
  Gtk::CheckButton* bitLengthButton1024 = nullptr;
  Gtk::CheckButton* bitLengthButton2048 = nullptr;
  Gtk::CheckButton* bitLengthButton4096 = nullptr;

  Glib::RefPtr<Gtk::Application> app;

  void add_key_button_clicked() {
    std::cerr << "add_key_button_clicked" << std::endl;
  }

  void encrypt_button_clicked() {
    std::cerr << "encrypt_button_clicked" << std::endl;
    decryptText->get_buffer()->set_text("i've been encrypted");
    decryptText->set_editable(false);
    encryptText->set_editable(true);
  }

  void decrypt_button_clicked() {
    std::cerr << "decrypt_button_clicked" << std::endl;
    encryptText->get_buffer()->set_text("i've been decrypted");
    encryptText->set_editable(false);
    decryptText->set_editable(true);
  }

  void save_rsa_key_button_clicked() {
    std::cerr << "save_rsa_key_button_clicked" << std::endl;
  }

  void save_dh_key_button_clicked() {
    std::cerr << "save_dh_key_button_clicked" << std::endl;
    auto ip = otherClientIPText->get_buffer()->get_text();
    if (ip.compare("") == 0) {
      std::cerr << "ip empty" << std::endl;
    } else {
      std::cerr<< ip << std::endl;
    }
  }

  void encryption_method_changed() {
    std::cerr << "encryption_method_changed" << std::endl;
    std::cerr << encryptionMethodSelection->get_active_text() << std::endl;
  }

  void ip_edited() {
    std::cerr << "ip_edited" << std::endl;
    std::cerr << otherClientIPText->get_buffer()->get_text() << std::endl;
  }

  void bit_length_selected() {
    if (
      bitLengthButton512->get_active() ||
      bitLengthButton1024->get_active() ||
      bitLengthButton2048->get_active() ||
      bitLengthButton4096->get_active()
    ) {
      std::cerr << "bit_length_selected" << std::endl;
      std::cerr << (bitLengthButton512->get_active() ? " 512     selected" : " 512 not selected") << std::endl;
      std::cerr << (bitLengthButton1024->get_active() ? "1024     selected" : "1024 not selected") << std::endl;
      std::cerr << (bitLengthButton2048->get_active() ? "2048     selected" : "2048 not selected") << std::endl;
      std::cerr << (bitLengthButton4096->get_active() ? "4096     selected" : "4096 not selected") << std::endl;
    }
  }

  void on_app_activate() {
    auto refBuilder = Gtk::Builder::create();
    try {
      refBuilder->add_from_file("assets/cryptohpc.ui");
    }
    catch(const Glib::FileError& ex) {
      std::cerr << "FileError: " << ex.what() << std::endl;
      return;
    }
    catch(const Glib::MarkupError& ex) {
      std::cerr << "MarkupError: " << ex.what() << std::endl;
      return;
    }
    catch(const Gtk::BuilderError& ex) {
      std::cerr << "BuilderError: " << ex.what() << std::endl;
      return;
    }

    mainWindow = refBuilder->get_widget<Gtk::Window>("MainWindow");
    if (!mainWindow) {
      std::cerr << "Could not get the window" << std::endl;
      return;
    }

    addKeyButton = refBuilder->get_widget<Gtk::Button>("AddKeyButton");
    encryptButton = refBuilder->get_widget<Gtk::Button>("EncryptButton");
    decryptButton = refBuilder->get_widget<Gtk::Button>("DecryptButton");
    saveRSAKeyButton = refBuilder->get_widget<Gtk::Button>("SaveRSAKeyButton");
    saveDHKeyButton = refBuilder->get_widget<Gtk::Button>("SaveDHKeyButton");

    if (!addKeyButton || !encryptButton || !decryptButton || !saveRSAKeyButton || !saveDHKeyButton) {
      std::cerr << "Could not get the buttons" << std::endl;
      return;
    }

    encryptionMethodSelection = refBuilder->get_widget<Gtk::ComboBoxText>("EncryptionMethodSelection");
    if (!encryptionMethodSelection) {
      std::cerr << "Could not get the combo text" << std::endl;
      return;
    }

    encryptText = refBuilder->get_widget<Gtk::TextView>("EncryptText");
    decryptText = refBuilder->get_widget<Gtk::TextView>("DecryptText");
    otherClientIPText = refBuilder->get_widget<Gtk::Entry>("OtherClientIPText");
    if (!encryptText || !decryptText || !otherClientIPText) {
      std::cerr << "Could not get the text" << std::endl;
      return;
    }

    bitLengthButton512 = refBuilder->get_widget<Gtk::CheckButton>("BitLengthButton512");
    bitLengthButton1024 = refBuilder->get_widget<Gtk::CheckButton>("BitLengthButton1024");
    bitLengthButton2048 = refBuilder->get_widget<Gtk::CheckButton>("BitLengthButton2048");
    bitLengthButton4096 = refBuilder->get_widget<Gtk::CheckButton>("BitLengthButton4096");
    if (!bitLengthButton512 || !bitLengthButton1024 || !bitLengthButton2048 || !bitLengthButton4096) {
      std::cerr << "Could not get the check buttons" << std::endl;
      return;
    }

    addKeyButton->signal_clicked().connect([]() {add_key_button_clicked();});
    encryptButton->signal_clicked().connect([]() {encrypt_button_clicked();});
    decryptButton->signal_clicked().connect([]() {decrypt_button_clicked();});
    saveRSAKeyButton->signal_clicked().connect([]() {save_rsa_key_button_clicked();});
    saveDHKeyButton->signal_clicked().connect([]() {save_dh_key_button_clicked();});

    encryptionMethodSelection->signal_changed().connect([](){encryption_method_changed();});

    bitLengthButton512->signal_toggled().connect([]() {bit_length_selected();});
    bitLengthButton1024->signal_toggled().connect([]() {bit_length_selected();});
    bitLengthButton2048->signal_toggled().connect([]() {bit_length_selected();});
    bitLengthButton4096->signal_toggled().connect([]() {bit_length_selected();});

    app->signal_window_removed().connect([](Gtk::Window* window) { delete window; });

    app->add_window(*mainWindow);
    mainWindow->set_visible(true);
  }
}

int main(int argc, char** argv) {
  app = Gtk::Application::create("org.gtkmm.example");
  app->signal_activate().connect([] () { on_app_activate(); });
  return app->run(argc, argv);
}