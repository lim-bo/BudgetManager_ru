#include "CourseWork.h"

const int BadFile = 0;
#ifndef Categories
#define Categories
enum class Category
{
	grossery,
	chemistry,
	beauty,
	communication,
	shopping,
	entertainment,
	income,
	nullCat
};
#endif

struct note_t {
	Category cat;
	uint32_t sum;
};

std::ostream& operator << (std::ostream& out, note_t note) {
	short catConst{};
	switch (note.cat) {
	case Category::grossery:
		catConst = 0;
		break;
	case Category::chemistry:
		catConst = 1;
		break;
	case Category::beauty:
		catConst = 2;
		break;
	case Category::communication:
		catConst = 3;
		break;
	case Category::shopping:
		catConst = 4;
		break;
	case Category::entertainment:
		catConst = 5;
		break;
	case Category::income:
		catConst = 6;
		break;
	}
	return out << catConst << "; " << note.sum << std::endl;
}

std::istream& operator >> (std::istream& in, note_t& note) {
	note_t newNote{};
	short got{};
	if (!(in >> got)) {
		return in;
	}
	switch (got) {
	case 0:
		newNote.cat = Category::grossery;
		break;
	case 1:
		newNote.cat = Category::chemistry;
		break;
	case 2:
		newNote.cat = Category::beauty;
		break;
	case 3:
		newNote.cat = Category::communication;
		break;
	case 4:
		newNote.cat = Category::shopping;
		break;
	case 5:
		newNote.cat = Category::entertainment;
		break;
	case 6:
		newNote.cat = Category::income;
	}
	in.ignore(2);
	if (!(in >> newNote.sum)) {
		return in;
	}
	note = newNote;
	return in;
}

#ifndef DataClass
#define DataClass
class DataBase {
private:
    List<note_t> rows;
	const char* dbPath = "../../../resources/db.csv";
public:

	DataBase() {
		try {
			init();
		}
		catch (...) {
			return;
		}
	}

	void addNote(Category cat, uint32_t sum) {
		note_t newNote = { cat, sum };
		this->rows.append(newNote);

		std::ofstream out(dbPath, std::ios_base::app);
		if (!out.is_open()) {
			out.close();
			throw BadFile;
		}
		out << newNote;
		out.close();
	}

	void init() {
		std::ifstream in(dbPath, std::ios_base::in);
		if (!in.is_open()) {
			in.close();
			throw BadFile;
		}
		while (in.good()) {
			if (in.eof()) {
				break;
			}
			note_t note{.cat = Category::nullCat};
			in >> note;
			if (note.cat != Category::nullCat)
				this->rows.append(note);
		}
		in.close();
	}

	void printRows(std::ostream& out) {
        rows.getList(out);
	}
};
#endif
