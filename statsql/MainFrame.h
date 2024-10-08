#pragma once
#include <wx/wx.h>
#include <mysqlx/xdevapi.h>
#include <wx/listctrl.h>
#include <wx/dataview.h>

class MainFrame : public wxFrame {
private:
	std::shared_ptr<mysqlx::Session> m_session = nullptr;

	wxStaticText* text = nullptr;
	wxStaticText* tables_text = nullptr;
	wxStaticText* display_current_table = nullptr;

	wxTextCtrl* create_db_text = nullptr;
	
	wxListBox* dbs_listbox = nullptr;
	wxListBox* tables_listbox = nullptr;

	wxRadioButton* rb_structure = nullptr;
	wxRadioButton* rb_data = nullptr;

	std::map<std::string, mysqlx::Type> m_types_map;
	wxButton* add_column_to_data_listbox_btn = nullptr;

	wxDataViewListCtrl* results_structure_listbox = nullptr;
	wxDataViewListCtrl* results_data_listbox = nullptr;

	wxString m_active_db;
	wxString m_active_table;
	wxDataViewListCtrl* m_active_structure_data_listbox = nullptr;

	wxString m_editing_start;
	wxString m_editing_done;

	wxVariant m_results_structure_rclick_item;

	int m_drop_db_index;
	int m_drop_table_index;
public:
	MainFrame(std::shared_ptr<mysqlx::Session> temp_session);

	void HandleDBsListboxDBLClick(wxCommandEvent& evt);
	void HandleTablesListboxDBLClick(wxCommandEvent& evt);

	// Helpers
	void RefreshDBList();
	void RefreshTablesList();
	void PopulateResultsList();

	// dbs_listbox context menu
	void OnDBsContextMenu(wxContextMenuEvent& evt);
	void SetDropDbIndex(wxMouseEvent& evt);
	// dbs_listbox context menu option click handlers
	void OnCreateDBClicked(wxCommandEvent& evt);
	void OnDropDBClicked(wxCommandEvent& evt);
	void OnRefreshDBClicked(wxCommandEvent& evt);

	// tables_listbox context menu
	void OnTablesContextMenu(wxContextMenuEvent& evt);
	void SetDropTableIndex(wxMouseEvent& evt);
	// tables_listbox context menu option click handlers
	void OnCreateTableClicked(wxCommandEvent& evt);
	void OnDropTableClicked(wxCommandEvent& evt);
	void OnRefreshTableClicked(wxCommandEvent& evt);

	// Radio buttons
	void HandleResultsStructureRB(wxCommandEvent& evt);
	void HandleResultsDataRB(wxCommandEvent& evt);

	// Results -> structure & data
	void HandleResultsEditStart(wxDataViewEvent& evt);
	void HandleResultsEditEnd(wxDataViewEvent& evt);
	void HandleResultsContextMenu(wxDataViewEvent& evt);

	// Results -> structure & data -> context menu option click handlers
	void OnCopyItemClicked(wxCommandEvent& evt);
	void OnDeleteRowClicked(wxCommandEvent& evt);
	void OnCopyRowClicked(wxCommandEvent& evt);
	void OnAddRowClicked(wxCommandEvent& evt);

	// Add row to results_data_listbox button
	void HandleAddRowToResultsDataListbox(wxMouseEvent& evt);
};
