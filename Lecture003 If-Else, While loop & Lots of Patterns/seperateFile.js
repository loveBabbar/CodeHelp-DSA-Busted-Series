var fs = require('fs');
var allfiles = fs.readdirSync('./main');

for(var i=0;i<allfiles.length;i++){
	const extension = allfiles[i].split(".").pop();

	let dir = `./${extension}Files`;
	if (!fs.existsSync(dir)){
    	fs.mkdirSync(dir);
	}
	  var currentPath = `./main/${allfiles[i]}`;
	  var newPath = `./${extension}Files/${allfiles[i]}`;
	  fs.copyFileSync(currentPath, newPath);
}
// constrl shift p
//terminus