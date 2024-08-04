# GavinaJPFinal
# Programmer: Jamie Gavina
# Email: jgavina@cnm.edu
# Purpose: A console-based quiz game that saves high scores.

import time

questions = [ #Source for questions https://pastquestionsandanswers.com/game-shows-trivia/
    {
        "question": "What is the Capital of France?",
        "choices": ["Paris", "London", "Berlin", "Madrid"],
        "answer": "Paris"
    },
    {
        "question": "Who wrote Hamlet?",
        "choices": ["William Shakespeare", "Charles Dickens", "J.K. Rowling", "George Orwell"],
        "answer": "William Shakespeare"
    },
    {
        "question": "Which planet is known as the Red Planet?",
        "choices": ["Earth", "Neptune", "Mars", "Jupiter"],
        "answer": "Mars"
    },
    {
        "question": "What is the longest river in the world?",
        "choices": ["Pecos", "Nile", "Gila", "Rio Grande"],
        "answer": "Nile"
    },
    {
        "question": "In the movie “Psycho,” what is the iconic murder weapon?",
        "choices": ["soap", "candle stick", "knife", "chainsaw"],
        "answer": "knife"
    }
]

def start_game():
    print("Welcome to the IQ quiz Game!")
    play_game()

def play_game():
    score = 0
    for question in questions:
        start_time = display_question(question)
        user_answer = get_user_input(start_time, time_limit=10)  # Set your desired time limit here
        if user_answer is None:
            continue  # Skip scoring for this question due to timeout or interruption
        elif user_answer == question["answer"]:
            score += 1
            print("Correct!")
        else:
            print("Incorrect.")
    save_high_score(score)

def get_user_input(start_time, time_limit=10):  # Default time limit is 10 seconds
    try:
        elapsed_time = time.time() - start_time
        if elapsed_time > time_limit:
            print("Time's up!")
            return None  # Return None to indicate timeout
        else:
            return input("Your answer: ").strip().lower()
    except KeyboardInterrupt:
        print("\nInterrupted by user.")
        return None

def save_high_score(score):
    try:
        with open("high_scores.txt", "r") as file:
            high_score = int(file.read())
        if score > high_score:
            with open("high_scores.txt", "w") as file:
                file.write(str(score))
            print(f"New High Score! {score}")
    except FileNotFoundError:
        # File does not exist, create it and save the score
        with open("high_scores.txt", "w") as file:
            file.write(str(score))
        print(f"First time playing! Your score: {score}")
    except ValueError:
        # Handle case where file is empty or contains invalid data
        with open("high_scores.txt", "w") as file:
            file.write(str(score))
        print(f"Score saved! Your score: {score}")

def display_question(question):
    print(question["question"])
    for i, choice in enumerate(question["choices"], start=1):
        print(f"{i}. {choice}")
    return time.time()  # Return the current time when the question starts

