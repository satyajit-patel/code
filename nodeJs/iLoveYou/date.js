let yesButton = document.getElementById("yes");
let noButton = document.getElementById("no");

function submit() {
    window.alert("congratulation you got a date with me..");
}
yesButton.addEventListener("click", submit);
noButton.addEventListener("click", submit);

//we will make her always click on Yes no matter what
noButton.addEventListener("mouseover", function crossChange() {
    noButton.innerHTML = "Yes";
    yesButton.innerHTML = "Yes";
});
noButton.addEventListener("mouseout", function prevVersion() {
    noButton.innerHTML = "No";
    yesButton.innerHTML = "Yes";
});
