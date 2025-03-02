/*
 * @Description: 
 * @Version: 1.0
 * @Autor: lei wang
 * @Date: 2021-09-09 13:53:33
 * @LastEditors: lei wang
 * @LastEditTime: 2021-11-08 11:39:55
 */
$(function() {
    // var totel = $("#totalCount").text(); 
    // total = getNum(totel)
    // var repetition = $("#repetition").text(); 
    // repetition = getNum(repetition)
    // var other = parseInt(total) - parseInt(repetition)
    // console.log(other)
    // let option = {
    //     title:{
    //         text: ""
    //     },
    //     // tooltip: {
    //     //     trigger: 'item',
    //     //     formatter: '{b} :{c0}'
    //     // },
    //     legend: {
    //         orient: 'vertical',
    //         left: 'right',
    //     },
    //     color : [ '#ee6666', '#8552a1', '#585eaa', '#7ed3f4', '#EF8D35' ],
    //     series: [
    //         {
    //             name: '',
    //             type: 'pie',
    //             radius: '50%',
    //             data: [
    //                 {value: repetition,name: "总文字复制"},
    //                 {value: other ,name: "没有问题"},
    //             ],
    //             label: {
    //                 //formatter: '{b}：{c}  ({d}%)',
    //                 formatter: '{b}:({d}%)',
    //             },
    //             emphasis: {
    //                 itemStyle: {
    //                     shadowBlur: 10,
    //                     shadowOffsetX: 0,
    //                     shadowColor: 'rgba(0, 0, 0, 0.5)'
    //                 }
    //             }
    //         }
    //     ]
    // };

    // var mychart = echarts.init(document.getElementById('myChart'));
    // mychart.setOption(option)

    // window.onresize = mychart.resize;




    $(".typeli").click(function() {
        var index = 0
        if (!$(this).hasClass("on")) {
            if ($(this).text() == "修改建议") {
                index = 1;
            }
            $(this).parents(".from").find(".typeli").removeClass("on")
            $(this).parents(".from").find(".typeli").eq(index).addClass("on")
            $(this).parents(".from").find(".suggest").hide();
            $(this).parents(".from").find(".source").hide();
            if (index) {
                $(this).parents(".from").find(".suggest").show();
            }  else {
                $(this).parents(".from").find(".source").show();
            }   
           
        }
       
    })

})


function getNum(data) {
    var numn = ''
    if (data.indexOf(',') != '-1') {
        data = data.split(",")
        for(var i = 0,len = data.length; i< len; i++) {
            numn+= data[i]
        }
    } else {
        numn = totel
    }
    return numn
}