const http=require('http');
const multiparty=require('multiparty');

http.createServer((req, res)=>{
    let form=new multiparty.Form({
        uploadDir: './upload'
    });

    form.parse(req);

    form.on('field', (name, value)=>{
        console.log('字段 : ', name, value);
    });

    form.on('file', (name, file)=>{
        console.log('文件 : ', name, file);
    });

    form.on('close', ()=>{
        console.log('表单解析完成');
    });

    form.off('off', ()=>{
        
    })
}).listen(8080);