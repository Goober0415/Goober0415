let currentPlayer;
const boardSize = 3;
let gameBoard = [];
let playerOneName = prompt("Enter Player One's name:");
let playerTwoName = prompt("Enter Player Two's name:");

function initializeGame() {
  gameBoard = Array(boardSize)
    .fill()
    .map(() => Array(boardSize).fill(""));
  currentPlayer = playerOneName;
  drawBoard();
}

function drawBoard() {
  let boardElement = document.getElementById("gameBoard");
  boardElement.innerHTML = ""; // Clear existing board
  gameBoard.forEach((row, i) => {
    let rowElement = document.createElement("tr");
    row.forEach((cell, j) => {
      let cellElement = document.createElement("td");
      cellElement.textContent = gameBoard[i][j];
      cellElement.addEventListener("click", () => makeMove(i, j));
      rowElement.appendChild(cellElement);
    });
    boardElement.appendChild(rowElement);
  });
}

function makeMove(row, col) {
  if (gameBoard[row][col] !== "" || checkWinner()) return; // Prevent moves on filled cells or after game ends
  gameBoard[row][col] = currentPlayer === playerOneName ? "X" : "O";
  drawBoard();
  if (!checkWinner()) switchPlayer(); // Switch player unless there's a winner
}

function checkWinner() {
  // Check rows, columns, and diagonals for a win
  for (let i = 0; i < boardSize; i++) {
    if (
      gameBoard[i].every((val) => val === gameBoard[i][0] && val !== "") ||
      gameBoard
        .map((row) => row[i])
        .every((val) => val === gameBoard[0][i] && val !== "")
    ) {
      alert(`${currentPlayer} wins!`);
      return true;
    }
  }
  if (
    (gameBoard[0][0] === gameBoard[1][1] &&
      gameBoard[1][1] === gameBoard[2][2] &&
      gameBoard[0][0] !== "") ||
    (gameBoard[0][2] === gameBoard[1][1] &&
      gameBoard[1][1] === gameBoard[2][0] &&
      gameBoard[0][2] !== "")
  ) {
    alert(`${currentPlayer} wins!`);
    return true;
  }
  return false;
}

function switchPlayer() {
  currentPlayer =
    currentPlayer === playerOneName ? playerTwoName : playerOneName;
}

function restartGame() {
  initializeGame();
}

initializeGame();
