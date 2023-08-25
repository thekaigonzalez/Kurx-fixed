require("definitions"); -- require before port to get definitions in certain dev env

require("port");

-- downloads a file from the internet and returns it in a string buffer
function svstr(wbs)
  save(wbs, "/tmp/site")
  
  fp = io.open("/tmp/site", "r")
  
  data = fp:read()
  
  fp:close()

  os.remove("/tmp/site")
  
  return data
end
