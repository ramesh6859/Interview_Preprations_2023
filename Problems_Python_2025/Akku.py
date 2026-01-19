import tkinter as tk
import json

# -------- LOAD EEG JSON (USER INPUT) -------- #
with open("eeg.json", "r") as f:
    eeg_data = json.load(f)

# -------- QUESTIONS -------- #
questions = [
    {"q": "Capital of India?", "opts": {"A": "Mumbai", "B": "Delhi", "C": "Chennai", "D": "Kolkata"}, "ans": "B"},
    {"q": "Python is a?", "opts": {"A": "Snake", "B": "OS", "C": "Language", "D": "Browser"}, "ans": "C"},
    {"q": "2 + 2 = ?", "opts": {"A": "3", "B": "4", "C": "5", "D": "6"}, "ans": "B"},
    {"q": "CPU full form?", "opts": {"A": "Central Unit", "B": "Central Processing Unit", "C": "Control Unit", "D": "Compute Unit"}, "ans": "B"},
    {"q": "Python comment symbol?", "opts": {"A": "//", "B": "#", "C": "/* */", "D": "<!--"}, "ans": "B"},
    {"q": "Mutable data type?", "opts": {"A": "Tuple", "B": "String", "C": "List", "D": "Int"}, "ans": "C"},
    {"q": "Loop keyword?", "opts": {"A": "repeat", "B": "for", "C": "loop", "D": "iterate"}, "ans": "B"},
    {"q": "GUI module in Python?", "opts": {"A": "numpy", "B": "tkinter", "C": "math", "D": "os"}, "ans": "B"},
    {"q": "Python file extension?", "opts": {"A": ".c", "B": ".java", "C": ".py", "D": ".txt"}, "ans": "C"},
    {"q": "Print function?", "opts": {"A": "echo()", "B": "print()", "C": "write()", "D": "show()"}, "ans": "B"}
]

# -------- QUIZ CLASS -------- #
class QuizCompetition:
    def __init__(self, root):
        self.root = root
        self.root.title("Quiz Competition")
        self.root.geometry("760x520")

        self.q_no = 0
        self.score = 0
        self.time_left = 5
        self.timer_id = None

        self.create_ui()
        self.load_question()

    def create_ui(self):
        tk.Label(
            self.root,
            text="QUIZ COMPETITION",
            font=("Arial", 22, "bold")
        ).pack(pady=10)

        self.question_label = tk.Label(
            self.root,
            font=("Arial", 16),
            wraplength=680
        )
        self.question_label.pack(pady=20)

        # OPTIONS (DISPLAY ONLY)
        self.option_labels = {}
        for opt in ["A", "B", "C", "D"]:
            lbl = tk.Label(self.root, font=("Arial", 14))
            lbl.pack(anchor="w", padx=240)
            self.option_labels[opt] = lbl

        self.feedback_label = tk.Label(
            self.root,
            font=("Arial", 14, "bold")
        )
        self.feedback_label.pack(pady=10)

        self.timer_label = tk.Label(
            self.root,
            font=("Arial", 14),
            fg="red"
        )
        self.timer_label.pack()

    def load_question(self):
        self.feedback_label.config(text="")
        self.time_left = 5

        q = questions[self.q_no]
        self.question_label.config(
            text=f"Q{self.q_no + 1}. {q['q']}"
        )

        for key, value in q["opts"].items():
            self.option_labels[key].config(text=f"{key}. {value}")

        # Immediately check answer using EEG JSON
        self.check_answer_from_json()
        self.update_timer()

    def eeg_to_option(self, eeg):
        if eeg < 0.45:
            return "A"
        elif eeg < 0.55:
            return "B"
        elif eeg < 0.65:
            return "C"
        else:
            return "D"

    def check_answer_from_json(self):
        eeg_value = eeg_data[self.q_no]
        user_answer = self.eeg_to_option(eeg_value)
        correct_answer = questions[self.q_no]["ans"]

        if user_answer == correct_answer:
            self.score += 1
            self.feedback_label.config(
                text=f"✔ Correct Answer (User: {user_answer})",
                fg="green"
            )
        else:
            self.feedback_label.config(
                text=f"✖ Wrong | Correct: {correct_answer} (User: {user_answer})",
                fg="red"
            )

    def update_timer(self):
        self.timer_label.config(
            text=f"Next question in {self.time_left} seconds"
        )

        if self.time_left > 0:
            self.time_left -= 1
            self.timer_id = self.root.after(1000, self.update_timer)
        else:
            self.next_question()

    def next_question(self):
        if self.timer_id:
            self.root.after_cancel(self.timer_id)

        self.q_no += 1
        if self.q_no < len(questions):
            self.load_question()
        else:
            self.show_result()

    def show_result(self):
        self.question_label.config(
            text=f"Quiz Completed!\nFinal Score: {self.score}/10"
        )
        self.feedback_label.config(text="")
        self.timer_label.config(text="")
        for lbl in self.option_labels.values():
            lbl.pack_forget()

# -------- RUN -------- #
root = tk.Tk()
QuizCompetition(root)
root.mainloop()