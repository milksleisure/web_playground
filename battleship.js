// Math.random() return real number in [0,1)
var location_1 = Math.floor(Math.random() * 5);
var location_2 = location_1 + 1;
var location_3 = location_1 + 2;

var guess;
var guesses = 0;
var hit = 0;
var isSunk = false;

while (!isSunk) {
    // get input
    guess = prompt("Ready, aim, fire! (enter a number 0-6):");
    if(guess < 0 || guess > 6) {
        alert("Please enter a valid number");
    } else {
        guesses++;
        if(guess == location_1) {
            location_1 = -1;
            hit++;
            alert("Hit!");
        } else if (guess == location_2) {
            location_2 = -1;
            hit++
            alert("Hit!");
        } else if (guess == location_3) {
            location_3 = -1;
            hit++;
            alert("Hit!");
        } else {
            alert("Miss!");
        }
        if(hit == 3) {
            isSunk = true;
            alert("Success!!");
        }
    }
}
var stats = "Total guesses: " + guesses + ". Accuracy: " + (3/guesses);
alert(stats);
