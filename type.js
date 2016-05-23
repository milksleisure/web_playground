function pt(element) {
    console.log(typeof(element));
}

pt(true);
pt({});
pt([]);
pt({"aa":123});
pt(["123",123]);
pt(function test(){return "123";});
pt(null);
pt(undefined);

if (99 == "99") {
    console.log("Number equals string!?");
} else {
    console.log("Expected here");
}

console.log(true == (true == "1"));
console.log(true === (true === "1"));

function Duck (sound) {
    this.sound = sound;
    this.quack = function() {console.log(this.sound);};
}

var toy = new Duck("quack");
toy.quack();

console.log(typeof(toy));
console.log(toy instanceof Duck);
