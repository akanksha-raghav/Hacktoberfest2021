var loader_script = '<div id="pre-loader">' +
    '<div class="spinner-border text-primary" role="status">' +
    '<span class="sr-only">Loading...</span>' +
    '</div>' +
    '</div>';
window.start_loader = function() {
    if ($('body>#pre-loader').length <= 0) {
        $('body').append(loader_script)
    }
}
window.end_loader = function() {
    var loader = $('body>#pre-loader')
    if (loader.length > 0) {
        loader.remove()
    }
}
var _loader = '<div class="tbl_loader"><div class="spinner-grow" style="width: 3rem; height: 3rem;" role="status"><span class="sr-only">Loading...</span></div><small>Please Wait..</small></div>'

$(function() {
    $('.dataTables_wrapper').each(function() {
        if ($(this).find('.tbl_loader').length <= 0)
            $(this).prepend(_loader)
    })

    $('#login').submit(function(e) {
        e.preventDefault();
        start_loader();
        if ($('.login-err').length > 0)
            $('.login-err').remove()
        $.ajax({
            url: './classes/URLshortener.php?a=login',
            data: $(this).serialize(),
            method: "POST",
            dataType: "json",
            error: function(err) {
                console.log(err)
                alert("An error occured.")
            },
            success: function(resp) {
                if (typeof resp == "object" && Object.keys(resp).length > 0) {
                    if (resp.status == "success") {
                        location.reload()
                    } else {
                        err = '<div class="alert alert-danger login-err">Incorrect Password</div>';
                        console.log(err)
                        $('#login [name="password"]').before(err)
                    }
                } else {
                    console.log(resp)
                    alert("An error occured.")
                }
                end_loader()
            }
        })
    })

    $('form#shorten').submit(function(e) {
        e.preventDefault()
        start_loader();
        $.ajax({
            url: './classes/URLshortener.php?a=shorten',
            data: $(this).serialize(),
            method: "POST",
            dataType: "json",
            error: function(err) {
                console.log(err)
                alert("An error occured.")
            },
            success: function(resp) {
                if (typeof resp == "object" && Object.keys(resp).length > 0) {
                    if (resp.status == "success") {
                        // console.log(resp.metas['title'], $.inArray('title', Object.keys(resp.metas)))
                        $('#result-img img').attr("src", '')
                        $('#result-img img').attr("src", './assets/img/browse.png')
                        $('#result-info #site-title').text("")
                        $('#result-info #site-description').text("")

                        if ($.inArray('og:image', Object.keys(resp.metas)) > -1)
                            $('#result-img img').attr("src", resp.metas['og:image'])
                        else
                            $('#result-img img').attr("src", './assets/img/browse.png')

                        $('#result-info #site-title').text("")
                        $('#result-info #site-description').text("")
                        if ($.inArray('title', Object.keys(resp.metas)) > -1)
                            $('#result-info #site-title').text(resp.metas['title'])
                        if ($.inArray('description', Object.keys(resp.metas)) > -1)
                            $('#result-info #site-description').text(resp.metas['description'])
                        $('#o_url').text($('[name="url"]').val())
                        $('#shorten_url').text("http://localhost/url_shortener/b?c=" + resp.code)
                        $('.shorten_url_link').attr("href", "http://localhost/url_shortener/b?c=" + resp.code)
                        $('#shorten-result').show('slow')
                    } else {
                        // console.log(resp, typeof resp)
                        console.log(resp)
                        alert("An error occured.")
                    }
                } else {
                    // console.log(resp, resp.length)
                    console.log(resp, Object.keys(resp).length)
                    alert("An error occured.")
                }
                end_loader()
            }
        })
    })
    $('#copy_to_clip').click(function(e) {
        e.preventDefault()
        $(this).attr('disabled', true)
        if ($('#to_copy').length > 0)
            $('#to_copy').remove()
        var _text = $(this).attr('href')
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
            $(this).closest('p').after(_msg)
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
})

function tbl_loader(tbl_id, show) {
    $('#' + tbl_id + "_wrapper").find('.tbl_loader').toggle(show)
    $('#' + tbl_id + "_wrapper").removeClass('blur')
    if (show == true) {
        $('#' + tbl_id + "_wrapper").find('.tbl_loader').css('display', "inline-flex")
        $('#' + tbl_id + "_wrapper").addClass('blur')
    }
}