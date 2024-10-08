#pragma once
#include <wx/wx.h>
#include <functional>
#include <mysqlx/xdevapi.h>

class MainFrame;

class DBPopup : public wxFrame {
private:
	wxTextCtrl* dbname = nullptr;
	std::shared_ptr<mysqlx::Session> _s;
public:
	std::function<void()> callback;

	DBPopup(std::shared_ptr<mysqlx::Session> temp_session, std::function<void()> cb, const wxString& title = "");

	void HandleCreateDBClick(wxMouseEvent& evt);
};
