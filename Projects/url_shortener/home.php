<div class="container">
    <h3><b>URL LIST</b></h3>
    <hr class="border-primary">
<div class="col-lg-12">
    <div class="w-100 d-flex justify-content-center align-items-center">
        <label for="" class="control-label">Search</label>
        <input type="text" class="form form-control col-sm-5 ml-2" id="search">
    </div>
    <div class="w-100 d-flex justify-content-end">
        <b>Total Items: <span id="total-item">-</span></b>
    </div>
    <div id="url-list">
        
    </div>
</div>
</div>
<div id="item-clone" class="d-none">
<div class="card p-1 url-item mb-2">
    <div class="card-body">
        <div class="w-100 d-flex-responsive">
            <div class="w-20">
                <div class="visit-counts img-thumbnail bg-primary w-100">10</div>
                <center><b>VISITS</b></center>
                <div class="d-flex justify-content-center">
                    <button class="btn btn-danger remove mr-2" type="button" title="Delete Data"><span class="fa fa-trash"></span></button>
                    <button class="btn btn-default border copy_to_clip ml-2" type="button" title="Copy Shorten URL to Clipboard"><span class="fa fa-clone"></span></button>
                </div>
            </div>
            <div class="w-60 p-2">
                <p class="m-0"><span class="text-muted"><b>Redirects to: </b></span><span class="url-link"></span></p>
                <p class="m-0"><span class="text-muted"><b>Shortened URL: </b></span><span class="url-short"></span></p>
                <p class="m-0"><span class="text-muted"><b>Created: </b></span><span class="url-created"></span></p>
                <p class="m-0"><span class="text-muted"><b>Last Browsed: </b></span><span class="url-last"></span></p>
            </div>
            <div class='w-20 url-data' style="display:none">
                <img src="" alt="" class="w-100 img-thubmnail site-img h-60" style="min-height:12vh;object-fit:contain">
                <hr>
                <p class="m-0 site-title truncate-2">Title</p>
                <small class="site-description truncate-2">Description</small>
            </div>
        </div>
    </div>
</div>
</div>
<?php if(isset($_SESSION['admin_login'])  && $_SESSION['admin_login']==true ): ?>
<script>
    $(function(){
        load_list()
        
    })
    window._search = function(){
        $('#search').on('input',function(){
            var s = $(this).val()
                s = s.toLowerCase()
                console.log($('#url-list').find('.url-item').length)
            // var _this = $(this)
            $('#url-list').find('.url-item').each(function(){
                var title = $(this).find('.site-title').text().toLowerCase()
                var desc = $(this).find('.site-description').text().toLowerCase()
                var url = $(this).find('.url-link').text().toLowerCase()
                if(title.includes(s) == true || desc.includes(s) == true || url.includes(s) == true)
                    $(this).toggle(true);
                else
                    $(this).toggle(false);
            })
            $('#total-item').text(parseFloat($('#url-list .url-item:visible').length).toLocaleString('en-us'))
                
        })
    }
    window.load_list = function load_list($s=''){
        start_loader();
        $.ajax({
            url: './classes/URLshortener.php?a=list_urls',
            data: {s:$s},
            method: "POST",
            dataType: "json",
            error: function(err) {
                console.log(err)
                alert("An error occured.")
            },
            success:function(resp){
                if (typeof resp == "object" && Object.keys(resp).length > 0) {
                    $('#url-list').html('')
                        $('#total-item').text(parseFloat(Object.keys(resp).length).toLocaleString('en-us'))
                    Object.keys(resp).map(function(k){
                        var card = $('#item-clone .url-item').clone()
                        card.find('.url-created').text(resp[k].date_created)
                        card.find('.url-last').text(resp[k].last_browsed)
                        card.find('.url-link').text(resp[k].url_redirect)
                        card.find('.visit-counts').text(resp[k].redirects)
                        card.find('.url-short').text("http://localhost/url_shortener/b?c="+resp[k].code)
                        card.attr('data-code',resp[k].code)
                        // console.log(card.html())
                        $('#url-list').append(card)
                        load_url(resp[k].url_redirect,card)
                    })

                }else{
                    $('#url-list').html('<center>No Data</center>')
                }
                end_loader()
            },
            complete:function(){
                _search()
                $('.copy_to_clip').click(function(e) {
                    e.preventDefault()
                    $(this).attr('disabled', true)
                    if ($('#to_copy').length > 0)
                        $('#to_copy').remove()
                    var _text = $(this).closest('.url-item').find('.url-short').text()
                    var _inp = $("<input type='text' id='to_copy'/>")
                    _inp.val(_text)
                    $(this).after(_inp)
                    _inp.focus()
                    _inp.select()
                    var is_copied = document.execCommand('copy')
                    if (is_copied) {
                        // alert("URL Copied to Clipboard")
                        var _msg = $('<div>')
                        _msg.addClass("alert alert-success mt-2")
                        _msg.text("URL Copied to Clipboard")
                        $(this).closest('.url-item').after(_msg)
                        setTimeout(function() {
                            _msg.hide('slow', function() {
                                _msg.remove()
                            })
                        }, 1500)
                    } else {
                        alert("URL fails to Copied to Clipboard")
                    }
                    _inp.remove()
                    $(this).attr('disabled', false)

                })
                $('.remove').click(function(){
                    start_loader()
                    var code = $(this).closest('.url-item').attr('data-code')
                    var conf = confirm("Are you sure to remove "+code+" permanently?")
                    if(conf == true)
                        delete_conf(code)
                    end_loader()
                })
            }
        })
    }
    window.delete_conf = function($code){
        start_loader()
        $.ajax({
            url: './classes/URLshortener.php?a=delete_url',
            data: {code:$code},
            method: "POST",
            dataType: "json",
            error: function(err) {
                console.log(err)
                alert("An error occured while deleting data.")
            },
            success:function(resp){
                if (typeof resp == "object" && Object.keys(resp).length > 0) {
                    if(resp.status == 'success'){
                        $('#url-list .url-item[data-code="'+$code+'"]').hide('slow',function () { $('#url-list .url-item[data-code="'+$code+'"]').remove });
                    }else{
                        console.log(resp)
                        alert("An error occured while deleting data.")
                    }
                }else{
                    console.log(resp)
                    alert("An error occured while deleting data.")
                    
                }
            }
        })
    }
    window.load_url = function($url= '',card){
        $.ajax({
            url: './classes/URLshortener.php?a=get_url',
            data: {url:$url},
            method: "POST",
            dataType: "json",
            error: function(err) {
                console.log(err)
                // alert("An error occured.")
            },
            success:function(resp){
                if (typeof resp == "object" && Object.keys(resp).length > 0) {
                        if ($.inArray('og:image', Object.keys(resp)) > -1)
                            card.find('.site-img').attr("src",resp['og:image']);
                        else
                            card.find('.site-img').attr("src",'./assets/img/browse.png');

                        if ($.inArray('title', Object.keys(resp)) > -1)
                            card.find('.site-title').text(resp['title']);
                        if ($.inArray('description', Object.keys(resp)) > -1)
                            card.find('.site-description').text(resp['description']);
                            card.find('.url-data').show('slow')
                        if(!resp['og:image'] && !resp['title'] && !resp['description'])
                            card.find('.url-data').remove();
                }else{
                    card.find('.url-data').remove()
                }
                }
            })
    }
    
</script>
<?php endif; ?>
