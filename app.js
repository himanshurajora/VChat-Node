const { static } = require("express");
var express = require("express");
var path = require("path")

var app = express();

app.use(express.static(path.join(__dirname, "views")));
app.set("view-engine", "ejs");

app.get("/", (req, res) => {
   res.sendFile(path.join(__dirname,'/login.html'))
})

app.get("/register", (req, res) =>{
    res.render("register.ejs");
})
app.listen(3000)
